#include "sa_world.h"

DECLARE_DYNAMIC_ARRAY(Level_t, LevelArray)

DEFINE_DYNAMIC_ARRAY(Level_t, LevelArray)

void CreateWorld(void)
{
    LevelArray levelArray;
    LevelArrayInit(&levelArray, 1);

    Level_t level;
    WallArrayInit(&level.walls, 10);
    Wall_t w1 = {};
    w1.x = 0; w1.y = 0;
    w1.wallType = WALL;
    WallArrayPush(&level.walls, w1);

    Wall_t w2 = {};
    w2.x = 0; w2.y = 0;
    w2.wallType = WALL;
    WallArrayPush(&level.walls, w2);

    for(size_t i = 0; i < level.walls.size; i++)
    {
        Wall_t w = level.walls.data[i];
        printf("%d.: (x=%d, y=%d)\n", i, w.x, w.y);
    }
}