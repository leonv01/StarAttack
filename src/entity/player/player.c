#include "player.h"

#include <raylib.h>

Camera3D camera;

void InitPlayer(float x, float y, float z)
{
    camera = (Camera){ 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;
}

void UpdatePlayer(void)
{
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
}

Camera3D GetPlayerCamera()
{
    return camera;
}