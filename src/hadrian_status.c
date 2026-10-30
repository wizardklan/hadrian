#include <stdio.h>

#include "../include/hadrian/hadrian_status.h"

void parse_hdn_status(HDN_STATUS_ENUM status)
{
    switch (status) {
        case HDN_SUCCESS:
            printf("HDN_SUCCESS: Process was executed with no errors.\n");
            break;
        case HDN_NULL_PTR_EXCEPTION:
            printf("HDN_NULL_PTR_EXCEPTION: Process was terminated due to encountering a null pointer which could not be handled.\n");
            break;
        case HDN_OUT_OF_MEMORY:
            printf("HDN_OUT_OF_MEMORY: Process was terminated due to error in memory allocation which could not be handled.\n");
            break;
        case HDN_OUT_OF_BOUNDS:
            printf("HDN_OUT_OF_BOUNDS: Array or iterator has been pushed out of valid\n");
            break;
        case HDN_INVALID_OPERATION:
            printf("HDN_INVALID_OPERATION: Non-standard operation occoured, likely due to invalid argument passed to function.\n");
            break;

        default:
            printf("Pass a `HDN_STATUS_ENUM` to get an error message.\n");
            break;
    }
}

