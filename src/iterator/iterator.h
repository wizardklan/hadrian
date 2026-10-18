#ifndef ITERATOR_H
#define ITERATOR_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define INVALID_ITERATOR ( (iterator){.data = NULL, .count = NAN, .index = NAN, .element_size = NAN} )

// data ptr is always at the HEAD (pointer to first element of array) while index changes.
// Rest fields stay constant after creation by createIterator().
typedef struct {
    void* data;
    size_t count;
    size_t index;
    size_t element_size;
    size_t start;
    size_t end;
} iterator;

iterator createIterator(void* array, size_t count, size_t element_size);
bool isInvalidIterator(iterator* itr);
void next(iterator* itr);
void destroyIterator(iterator* itr);
void advance(iterator* itr, const size_t step);
void prev(iterator* itr);
void* getIteratorValue(iterator* itr);
void swapIterators(iterator* first, iterator* second);
bool iteratorEqual(const iterator* itr1, const iterator* itr2);
int iteratorSeperation(const iterator* firstItr, const iterator* secondItr);
void* iteratorRaw(iterator* itr);
iterator createRangeIterator(void* array, size_t count, size_t element_size, const size_t start, const size_t end);

#endif /* ITERATOR_H */
