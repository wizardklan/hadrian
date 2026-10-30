#ifndef ITERATOR_H
#define ITERATOR_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "hadrian_status.h"

#define INVALID_ITERATOR ((iterator){0})

// data ptr is always at the HEAD (pointer to first element of array) while index changes.
// Rest fields stay constant after creation by createIterator().
typedef struct {
    void* data;
    size_t count;
    size_t index;
    size_t element_size;
    size_t start;
    size_t end;
    int direction;
} iterator;

iterator createIterator(void* array, size_t count, size_t element_size);
bool isInvalidIterator(const iterator* itr);
void next(iterator* itr);
void destroyIterator(iterator* itr);
void advance(iterator* itr, const size_t step);
void prev(iterator* itr);
void* getIteratorValue(iterator* itr);
HDN_STATUS_ENUM swapIterators(iterator* first, iterator* second);
bool iteratorEqual(const iterator* itr1, const iterator* itr2);
ptrdiff_t iteratorSeparation(const iterator* firstItr, const iterator* secondItr);
HDN_STATUS_ENUM iteratorRaw(iterator *itr, void* value);
iterator createRangeIterator(void* array, size_t count, size_t element_size, const size_t start, const size_t end, const int direction);
HDN_STATUS_ENUM setCurrentIteratorValue(iterator* itr, const void* value);

#endif /* ITERATOR_H */
