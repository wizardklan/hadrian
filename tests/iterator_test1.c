// iterator_test1.c - Tests on the iterator.h by comparing with standard C actions.

#include <stdio.h>
#include <string.h>

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

    char str1[] = "test string 1";
    char str2[] = "test string 2";
    iterator iSTR1 = createIterator(str1, strlen(str1), sizeof(str1[0]));
    iterator iSTR2 = createIterator(str2, strlen(str2), sizeof(str2[0]));

    if (iteratorEqual(&iSTR1, &iSTR2)) {
        printf("Both iterators to strings are equal (SHOULD RETURN FALSE).\n");
    } else {
        printf("Iterators to strings are not equal (SHOULD RETURN TRUE).\n");
    }

    char* value = ((char*)iteratorRaw(&iSTR1));
    printf("Value of raw pointer to iterator: %p\n", value);
    printf("Value at raw pointer to iterator: %c\n", *value);

    printf("Value of increment on raw pointer from iterator: %p\n", value+1);
    printf("Value at increment on raw pointer from iterator (should return 'e'): %c\n", *(value+1));


    return 0;
}
