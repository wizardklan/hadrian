/*
    hadrian_status.h - Error constants for Hadrian.

    Use whereever a function must return a ptr by changing to HDN_STATUS_ENUM
    & modifying the ptr and returning a status constant.
*/

#ifndef HADRIAN_STATUS_H
#define HADRIAN_STATUS_H

typedef enum {
    HDN_SUCCESS = 0,
    HDN_NULLPTREXCEPTION,
    HDN_OUTOFMEMORY,
    HDN_OUTOFBOUNDS,
    HDN_INVALID_OPERATION
} HDN_STATUS_ENUM;

#endif // HADRIAN_STATUS_H
