#ifndef __SA_WALL_H
#define __SA_WALL_H

#include <stdlib.h>

typedef enum
{
    WALL,
    DOOR,
    WINDOW,
    GLASS,
    VERTICAL_SLOPE,
    HORIZONTAL_SLOPE
} WALL_TYPE;

typedef struct 
{
    size_t x;
    size_t y;
    WALL_TYPE wallType;
} Wall_t;

#endif // __SA_WALL_H