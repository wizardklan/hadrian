#include <stdlib.h>
#include <string.h>

#define GENERIC_PTR_INC(ptr, count, elem_size) \
    ((void *)((char *)(ptr) + ((count) * (elem_size))))
#define GENERIC_PTR_DEC(ptr, count, elem_size) \
    ((void *)((char *)(ptr) - ((count) * (elem_size))))

void reverseArray(void* array, size_t count, size_t element_size)
{
    char* left = (char*)(array);
    char* right = (char*)(GENERIC_PTR_INC(array, count-1, element_size));
    char* tmp = (char*)(NULL);

    do {
        for (size_t i = 0; i < element_size; i++) {
            tmp[i] = left[i];
            left[i] = right[i];
            right[i] = tmp[i];
        }
        left += element_size;
        right -= element_size;
    } while (left < right);
}

// NOTE: Can be improved via sentinal search.
// TODO:                     ^ 
int linearSearch(const void* array, const void* member, size_t count, size_t element_size)
{
    const void* itr = array;
    for (size_t i = 0; i <= count; i++) {
        if (memcmp(GENERIC_PTR_INC(itr, i, element_size), member, element_size)) {
            return i;
        }
    }
    return -1;
}

size_t repetitions(const void* array, const void* member, size_t count, size_t element_size)
{
    int sum = 0;

    const void* itr = array;
    for (size_t i = 0; i <= count; i++) {
        if (memcmp(GENERIC_PTR_INC(itr, i, element_size), member, element_size)) {
            sum++;
        }
    }
    return sum;
}

void fillArray(void* array, const void* value, size_t count, size_t element_size)
{
    for (size_t i = 0; i <= count; i++) {
        memcpy(GENERIC_PTR_INC(array, 1, element_size), value, element_size);
    }
    return;
}

static inline int compare_ints(const void *a, const void *b) {
    int int_a = *((const int *)a);
    int int_b = *((const int *)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

void sort(void* array, size_t count, size_t element_size)
{
    qsort(array, count, element_size, compare_ints);
    return;
}
