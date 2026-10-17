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
        .element_size = element_size
    };
    return itr;
}

// Takes reference to a pre-existing iterator.
// Compares iterator taken as function argument to INVALID_ITERATOR (defined in iterator.h) and returns bool.
bool isInvalidIterator(iterator* itr)
{
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
    if (itr->index == itr->count) {
        fprintf(stderr, "Iterator cannot go out of bounds of its array.\n");
        return;
    }

    // itr->data = GENERIC_AT_PTR_INCREMENT(itr->data, 1, itr->element_size);
    itr->index += 1;
}

// Iterator exists as a struct on the stack, attempts to remove it and sets dangling pointer to NULL
// Essentially makes the iterator unusable
void destroyIterator(iterator* itr)
{
    free(itr->data);
    itr->data = NULL;
    free(itr);
    itr = NULL;
}

// Advances iterator by given input (const size_t step) by incrementing iterator's index by step.
void advance(iterator* itr, const size_t step)
{
    if (isInvalidIterator(itr)) {
        return;
    }
    if (itr->index == itr->count) {
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
    if (itr->index <= 0) {
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
// int value = *(int*)getIteratorValue(&itr);
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
// Needs to either rewritten.
void swapIterators(iterator* first, iterator* second)
{
    iterator temp = *first;
    *first = *second;
    *second = temp;

    return;
}
