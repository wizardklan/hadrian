/*
    hadrian_status.h - Error constants for Hadrian.

    Use whereever a function must return a ptr by changing to HDN_STATUS_ENUM
    & modifying the ptr and returning a status constant.
*/

#ifndef HADRIAN_STATUS_H
#define HADRIAN_STATUS_H

#include <stdio.h>

typedef enum {
    HDN_SUCCESS = 0,
    HDN_NULL_PTR_EXCEPTION,
    HDN_OUT_OF_MEMORY,
    HDN_OUT_OF_BOUNDS,
    HDN_INVALID_OPERATION
} HDN_STATUS_ENUM;

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

#endif // HADRIAN_STATUS_H
