#ifndef __SA_TILE_H
#define __SA_TILE_H

#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#include "sa_wall.h"
#include "sa_floor.h"
#include "sa_ceiling.h"

typedef struct
{  
    Vector2 position;
    Wall_t wall;
    bool solid;
    Floor_t floor;
    Ceiling_t ceiling;
} Tile_t;

#endif // __SA_TILE_H