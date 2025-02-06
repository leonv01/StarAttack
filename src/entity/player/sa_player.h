#ifndef __SA_PLAYER_H
#define __SA_PLAYER_H

#include <raylib.h>

void InitPlayer(float x, float y, float z);
void UpdatePlayer(void);
Camera3D GetPlayerCamera();

#endif // __SA_PLAYER_H