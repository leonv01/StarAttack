#ifndef __PLAYER_H
#define __PLAYER_H

#include <raylib.h>

void InitPlayer(float x, float y, float z);
void UpdatePlayer(void);
Camera3D GetPlayerCamera();

#endif // __PLAYER_H