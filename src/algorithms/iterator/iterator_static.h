/*
    iterator_static.h

    Functions & algorithms using iterators.
 */

#ifndef ITERATOR_STATIC_H
#define ITERATOR_STATIC_H

#include <stdbool.h>
#include "../../iterator/iterator.h"

// Returns the index of the first instance of `member` in the array.
iterator linearSearch(const void* array, const void* member, size_t count, size_t element_size);

#endif // ITERATOR_STATIC_H
