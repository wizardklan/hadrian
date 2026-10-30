/*
    hadrian_status.h - Error constants for Hadrian.

    Use whereever a function must return a ptr by changing to HDN_STATUS_ENUM
    & modifying the ptr and returning a status constant.
*/

#ifndef HADRIAN_STATUS_H
#define HADRIAN_STATUS_H

typedef enum {
    HDN_SUCCESS = 0,
    HDN_NULL_PTR_EXCEPTION,
    HDN_OUT_OF_MEMORY,
    HDN_OUT_OF_BOUNDS,
    HDN_INVALID_OPERATION
} HDN_STATUS_ENUM;

void parse_hdn_status(HDN_STATUS_ENUM status);
#endif // HADRIAN_STATUS_H
