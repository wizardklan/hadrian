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

bool isInvalidIterator(iterator* itr)
{
    iterator b = INVALID_ITERATOR;

    if (itr->data == b.data && itr->count == b.count && itr->index == b.index && itr->element_size == b.element_size) {
        return true;
    } else {
        return false;
    }
}

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

void destroyIterator(iterator* itr)
{
    free(itr->data);
    itr->data = NULL;
    free(itr);
    itr = NULL;
}

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

void swapIterators(iterator* first, iterator* second)
{
    iterator temp = *first;
    *first = *second;
    *second = temp;

    return;
}
