#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "iterator.h"

// #define GENERIC_AT_PTR_INCREMENT(ptr, i, element_size) \
//     ((void *)((char *)(ptr) + ((i) * (element_size))))
//
// #define GENERIC_AT_PTR_DECREMENT(ptr, i, element_size) \
//     ((void *)((char *)(ptr) + ((i) * (element_size))))


// Takes a pointer to the first element of an array along with its count (sizeof(arr)/sizeof(arr[0])) & element_size (sizeof(arr[0]))
// Sets iterator data ptr as a constant reference to the HEAD (first element) of the given array and begins indexing at 0 while filling other fields.
//
// Iterator created exists over entire array unlike rangeIterator hence start = 0 & end = count.
iterator createIterator(void* array, size_t count, size_t element_size)
{
    if (array == NULL) {
        fprintf(stderr, "Array contains NULL value.\n");
        return INVALID_ITERATOR;
    }

    iterator itr = {
        .data = array,
        .count = count,
        .index = 0,
        .element_size = element_size,
        .start = 0,
        .end = count
    };
    return itr;
}

// Takes reference to a pre-existing iterator.
// Compares iterator taken as function argument to INVALID_ITERATOR (defined in iterator.h) and returns bool.
bool isInvalidIterator(iterator* itr) {
    iterator b = INVALID_ITERATOR;

    if (itr->data == b.data && itr->count == b.count && itr->index == b.index && itr->element_size == b.element_size) {
        return true;
    } else {
        return false;
    }
}

// Takes reference to pre-existing iterator.
// The data ptr of the iterator is always at the HEAD of its array, the index of the iterator is **incremented** by **1**.
void next(iterator* itr)
{
    if (isInvalidIterator(itr)) {
        return;
    }
    if (itr->index >= itr->end) {
        fprintf(stderr, "Iterator cannot go out of bounds of its array.\n");
        return;
    }

    // itr->data = GENERIC_AT_PTR_INCREMENT(itr->data, 1, itr->element_size);
    itr->index += 1;
}

// New implementation:
// Simply assigns INVALID_ITERATOR
void destroyIterator(iterator* itr)
{
    if (itr->data == NULL) {
        return;
    }

    *itr = INVALID_ITERATOR;
    return;
}

// Advances iterator by given input (const size_t step) by incrementing iterator's index by step.
void advance(iterator* itr, const size_t step)
{
    if (isInvalidIterator(itr)) {
        return;
    }
    if (itr->index >= itr->end) {
        fprintf(stderr, "Iterator cannot go out of bounds of its array.\n");
        return;
    }

    // itr->data = GENERIC_AT_PTR_INCREMENT(itr->data, 1, itr->element_size);
    itr->index += step;
}

// Decrements iterator by **1** by decrementing its index.
void prev(iterator* itr)
{
    if (isInvalidIterator(itr)) {
        return;
    }
    if (itr->index <= itr->start) {
        fprintf(stderr, "Iterator cannot go out of bounds of its array.\n");
        return;
    }

    // itr->data = GENERIC_AT_PTR_INCREMENT(itr->data, 1, itr->element_size);
    itr->index -= 1;
}

// Returns a char* of the value the iterator's index is currently at, due to C's void type having 0 size it is casted to a char* (size(char) == 1)
//
// The iterator's data ptr is always at its array's HEAD and returns (data+index) hence retrieving the value the index is currently at.
//
// To use, the function's return has to be de-referenced and typecast into the array's type.
//
// If an iterator `itr` is created on an integer array.
// int value = *((int*)getIteratorValue(&itr));
// ^^^ Correct syntax
void* getIteratorValue(iterator* itr)
{
    if (isInvalidIterator(itr)) {
        fprintf(stderr, "Iterator provided is NULL.");
        return NULL;
    }
    if (itr->index == itr->count) {
        fprintf(stderr, "Cannot call element out side bounds of the array.");
        return NULL;
    }

    return (char*)itr->data + itr->index * itr->element_size;
}

// Swaps the whole iterator.
//
// Note (UNDEFINED BEHAVIOR): Due to the void*, this might try and swap 2 iterators of different type.
// TODO: Needs to be rewritten.
void swapIterators(iterator* first, iterator* second)
{
    iterator temp = *first;
    *first = *second;
    *second = temp;

    return;
}

// Compares each member of 2 iterators and returns corresponding bool.
//
// NOTE: Will return even if data ptr is NULL and/or the iterator is an INVALID_ITERATOR.
//
// This along with swapIterators() suffer from the same problem, we can't know whether both iterators exist on the same array.
bool iteratorEqual(const iterator *itr1, const iterator *itr2)
{
    if (itr1->data == itr2->data && itr1->count == itr2->count && itr1->element_size == itr2->element_size && itr1->index == itr2->index) {
        return true;
    } else {
        return false; 
    }
}

// Returns raw pointer to current (data+index)
//
// This also suffers from the same problem as swapIterators() & iteratorEqual(), there is no way of knowing which array the iterator exists on
// hence only returning a pointer to that specific member of the array, an array is contiguous so pointer arithmetic is still valid on this ptr
// but its still a point of caution.
void* iteratorRaw(iterator *itr)
{
    if (itr->data == NULL || isInvalidIterator(itr)) {
        fprintf(stderr, "Iterator is invalid.");
// NOTE: Stating the iterator is invalid then just procedding nullptr doesn't make sense since thats the value of an invalid  iterator anyway. 
// TODO: Choose better return than nullptr as it kills the point of nullcheck.
        return NULL;
    } else {
       return getIteratorValue(itr);
    }
}

// Returns the seperation between iterators as an integer hence **value can be negative** since the order of the parameters matters.
// Negative value indicates first iterator is behind the second in index.
//
// NOTE: Does not work for rangeIterator
int iteratorSeparation(const iterator *firstItr, const iterator *secondItr)
{
    if (firstItr->data == NULL || secondItr == NULL) {
        fprintf(stderr, "Iterators are invalid.");
        return NAN;
    }

    return firstItr->index - secondItr->index;
}

// Returns an iterator that exists only in a slice of an array but limiting its count to exist only between start and end.
// Hence iterator exists only in (start-end) i.e. a rangeIterator.
//
// Will return out of bounds if moved outside its range even if accessing that memory is valid.
iterator createRangeIterator(void *array, size_t count, size_t element_size, const size_t start, const size_t end)
{
    if (array == NULL) {
        fprintf(stderr, "Array is invalid.");
        return INVALID_ITERATOR;
    }

    return (iterator){
        .data = array,
        .count = start - end,
        .element_size = element_size,
        .start = start,
        .end = end
    };
}
