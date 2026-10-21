#include <stdbool.h>
#include <string.h>

#include "iterator_static.h"

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
