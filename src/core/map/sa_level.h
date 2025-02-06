#ifndef __SA_LEVEL_H
#define __SA_LEVEL_H

#include <stdlib.h>
#include "sa_wall.h"
#include "../utils/sa_structures.h"

DECLARE_DYNAMIC_ARRAY(Wall_t, WallArray)  // Only declare the struct and functions

typedef struct 
{
    WallArray walls;
    size_t width;
    size_t height;
    size_t levels;
} Level_t;

Level_t LevelCreate(WallArray array, size_t width, size_t height, size_t levels);
void LevelDestroy(Level_t *level);

void LevelAddWalls(Level_t *level, WallArray walls);
void LevelRemoveWall(Level_t *level, size_t x, size_t y);

#endif // __SA_LEVEL_H