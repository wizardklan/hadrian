/*
    iterator_static.h

    Functions & algorithms using iterators.
 */

#ifndef ITERATOR_STATIC_H
#define ITERATOR_STATIC_H

#include "../../iterator/iterator.h"

// Returns an iterator to the first occurrence of `member`.
iterator iteratorLinearSearch(iterator itr, const void *member);

// Returns an iterator to the last occurrence of `member`.
iterator iteratorReverseLinearSearch(iterator itr, const void *member);

// Returns the number of occurrences of `member`.
size_t iteratorCountOccurrences(iterator itr, const void *member);

// Returns true if `member` exists.
bool iteratorContains(iterator itr, const void *member);

// Reverses the elements in the iterator's range.
HDN_STATUS_ENUM iteratorReverse(iterator itr);

// Fills every element in the iterator's range with the specified value.
HDN_STATUS_ENUM iteratorFill(iterator itr, const void *value);

// Replaces the first occurrence of `old_value` with `new_value`.
HDN_STATUS_ENUM iteratorReplace(iterator itr,
                                const void *old_value,
                                const void *new_value);

// Replaces every occurrence of `old_value` with `new_value`.
size_t iteratorReplaceAll(iterator itr,
                          const void *old_value,
                          const void *new_value);

// Swaps the elements pointed to by two iterators.
HDN_STATUS_ENUM iteratorSwap(iterator first, iterator second);

// Copies the contents of one iterator range into another.
HDN_STATUS_ENUM iteratorCopy(iterator source, iterator destination);

// Moves the contents of one iterator range into another.
HDN_STATUS_ENUM iteratorMove(iterator source, iterator destination);

// Swaps two iterator ranges element by element.
HDN_STATUS_ENUM iteratorSwapRanges(iterator first, iterator second);

// Sorts the iterator's range.
HDN_STATUS_ENUM iteratorSort(iterator itr,
                             int (*comparator)(const void *, const void *));

// Returns true if the iterator's range is sorted.
bool iteratorIsSorted(iterator itr,
                      int (*comparator)(const void *, const void *));

// Performs a binary search on the iterator's range.
iterator iteratorBinarySearch(iterator itr,
                              const void *key,
                              int (*comparator)(const void *, const void *));

// Returns an iterator to the smallest element.
iterator iteratorMin(iterator itr,
                     int (*comparator)(const void *, const void *));

// Returns an iterator to the largest element.
iterator iteratorMax(iterator itr,
                     int (*comparator)(const void *, const void *));

// Applies a function to every element in the iterator's range.
HDN_STATUS_ENUM iteratorForEach(iterator itr,
                                void (*function)(void *));

// Applies a transformation function to every element.
HDN_STATUS_ENUM iteratorTransform(iterator source,
                                  iterator destination,
                                  void (*function)(const void *, void *));

// Returns true if every element satisfies the predicate.
bool iteratorAllOf(iterator itr,
                   bool (*predicate)(const void *));

// Returns true if at least one element satisfies the predicate.
bool iteratorAnyOf(iterator itr,
                   bool (*predicate)(const void *));

// Returns true if no elements satisfy the predicate.
bool iteratorNoneOf(iterator itr,
                    bool (*predicate)(const void *));

#endif // ITERATOR_STATIC_H
