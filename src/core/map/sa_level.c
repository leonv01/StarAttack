#include "sa_level.h"
#include "../utils/sa_structures.h"

DEFINE_DYNAMIC_ARRAY(Wall_t, WallArray)

Level_t LevelCreate(WallArray array, size_t width, size_t height, size_t levels)
{
    Level_t level;

    level.walls = array;
    level.width = width;
    level.height = height;
    level.levels = levels;

    return level;
}

void LevelDestroy(Level_t *level)
{
    WallArrayFree(&level->walls);
}

void LevelAddWalls(Level_t *level, WallArray walls)
{
    for(size_t i = 0; i < walls.size; i++)
    {
        WallArrayPush(&level->walls, walls.data[i]);
    }
}

void LevelRemoveWall(Level_t *level, size_t x, size_t y)
{
    // TODO:
}