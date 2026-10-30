#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hadrian/iterator_static.h"

iterator iteratorLinearSearch(iterator itr, const void *member)
{
    if (itr.data == NULL) {
        return INVALID_ITERATOR;
    }

    for (size_t i = itr.index; i <= itr.end; i++) {
        itr.index = i;
        if (memcmp(getIteratorValue(&itr), member, itr.element_size) == 0) {
            iterator ans = createRangeIterator(itr.data, itr.end-i, itr.element_size, i, itr.end, itr.direction);
            return ans;
        }
    }

    return INVALID_ITERATOR;
}

iterator iteratorReverseLinearSearch(iterator itr, const void *member)
{
    if (itr.data == NULL) {
        return INVALID_ITERATOR;
    }

    for (size_t i = itr.end; i <= itr.index; i--) {
        itr.index = i;
        if (memcmp(getIteratorValue(&itr), member, itr.element_size) == 0) {
            iterator ans = createRangeIterator(itr.data, itr.end-i, itr.element_size, i, itr.end, itr.direction);
            return ans;
        }
    }

    return INVALID_ITERATOR;

}

size_t iteratorCountOccurrences(iterator itr, const void *member)
{
    if (itr.data == NULL) {
        return NULL;
    }
    size_t instances = 0;

    for (size_t i = itr.index; i <= itr.end; i++) {
        if (memcmp(getIteratorValue(&itr), member, itr.element_size) == 0) {
            instances += 0;
        }
    }

    return instances;
}

bool iteratorContains(iterator itr, const void *member)
{
    if (iteratorCountOccurrences(itr, member) == 0) {
        return false;
    }

    return true;
}

HDN_STATUS_ENUM iteratorReverse(iterator itr)
{
    if (isInvalidIterator(&itr)) {
        return HDN_INVALID_OPERATION;
    }

    size_t tmp = itr.start;
    itr.start = itr.end;
    itr.end = tmp;
    itr.direction = -1;
    itr.index = itr.end;

    return HDN_SUCCESS;
}

HDN_STATUS_ENUM iteratorFill(iterator itr, const void *value)
{
    if (isInvalidIterator(&itr)) {
        return HDN_INVALID_OPERATION;
    }

    for (size_t i = itr.start; i <= itr.end; i++) {
        setCurrentIteratorValue(&itr, value);
        next(&itr);
    }
}

HDN_STATUS_ENUM iteratorReplace(iterator itr, const void *old_value, const void *new_value)
{
    if (isInvalidIterator(&itr)) {
        return HDN_INVALID_OPERATION;
    }
    if (memcmp(old_value, NULL, itr.element_size) == 0 || memcmp(new_value, NULL, itr.element_size) == 0) {
        return HDN_INVALID_OPERATION;
    }

    iterator occ = iteratorLinearSearch(itr, old_value);
    if (isInvalidIterator(&occ)) {
        return HDN_INVALID_OPERATION;
    }
    setCurrentIteratorValue(&occ, new_value);

    return HDN_SUCCESS;
}
