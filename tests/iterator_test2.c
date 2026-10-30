#include <assert.h>
#include <stdio.h>

#include "../include/hadrian/iterator.h"
#include "../include/hadrian/hadrian_status.h"

int main(void)
{
    int values[] = {10, 20, 30, 40, 50};

    iterator itr = createIterator(values, 5, sizeof(int));

    assert(!isInvalidIterator(&itr));
    assert(*(int*)getIteratorValue(&itr) == 10);

    next(&itr);
    assert(*(int*)getIteratorValue(&itr) == 20);

    advance(&itr, 2);
    assert(*(int*)getIteratorValue(&itr) == 40);

    prev(&itr);
    assert(*(int*)getIteratorValue(&itr) == 30);
    // fails here ^^^

    iterator itr2 = createIterator(values, 5, sizeof(int));

    advance(&itr2, 2);

    assert(iteratorEqual(&itr, &itr2));
    assert(iteratorSeparation(&itr, &itr2) == 0);

    swapIterators(&itr, &itr2);

    assert(*(int*)getIteratorValue(&itr) == 30);
    assert(*(int*)getIteratorValue(&itr2) == 30);

    void* rawPtrToIterator;
    assert(iteratorRaw(&itr, rawPtrToIterator) == HDN_SUCCESS);

    iterator range = createRangeIterator(values, 5, sizeof(int), 1, 4);

    assert(*(int*)getIteratorValue(&range) == 10);
    next(&range);
    assert(*(int*)getIteratorValue(&range) == 20);

    destroyIterator(&itr);
    destroyIterator(&itr2);
    destroyIterator(&range);

    printf("All iterator tests passed\n");

    return 0;
}
