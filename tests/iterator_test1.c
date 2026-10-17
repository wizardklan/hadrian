// iterator_test1.c - Tests on the iterator.h by comparing with standard C actions.

#include <stdio.h>

#include "../src/iterator/iterator.h"

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    iterator itr = createIterator(nums, sizeof(nums)/sizeof(nums[0]), sizeof(nums[0]));

    printf("Pointer to nums head: %p\n", nums);
    printf("Pointer of iterator: %p\n\n", itr.data);

    printf("Value of nums head: %d\n", *nums);
    printf("Value of nums head via iterator: %d\n\n", *(int*)getIteratorValue(&itr));

    next(&itr);

    printf("Incremented value of itr of nums by 1.\n");
    printf("Value of nums head: %d\n", *(nums+1));
    printf("Value of nums head via iterator: %d\n\n", *(int*)getIteratorValue(&itr));

    advance(&itr, 5);

    printf("Incremented value of itr of nums by 5 over.\n");
    printf("Value of nums head: %d\n", *(nums+6));
    printf("Value of nums head via iterator: %d\n\n", *(int*)getIteratorValue(&itr));

    return 0;
}
