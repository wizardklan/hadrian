/*
    carrays_static.h

    Generic operations on contiguous C arrays.

    Implementation:
    1. Performs no dynamic memory allocation.
    2. Operates directly on caller-provided memory.
    3. Does not create or return arrays.

    Notes:
    1. The caller is responsible for supplying valid pointers,
       element counts and element sizes.
*/

#ifndef CARRAYS_STATIC_H
#define CARRAYS_STATIC_H

#include <stddef.h>
#include <stdbool.h>

#include "hadrian_status.h"

// Reverses the members of a given array.
void reverseArray(void* array, size_t count, size_t element_size);
// Returns the index of the first instance of `member` in the array.
// Returns -1 if no instances are found
int linearSearch(const void* array, const void* member, size_t count, size_t element_size);
// Returns number of times `member` occours in the array.
size_t repetitions(const void* array, const void* member, size_t count, size_t element_size);
// Replaces all values in array with `value` 
void fillArray(void* array, const void* value, size_t count, size_t element_size);
// Sorts all members in ascending order.
// NOTE: Only for num-type arrays. This is for the user to specifiy we don't check for this.
void sort(void* array, size_t count, size_t element_size);

#endif // CARRAYS_STATIC_H
