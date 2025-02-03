#include "render.h"

#include <raylib.h>

#include "../../entity/player/player.h"

// TODO: Change to load screen config from file
static int screenWidth = 1280;
static int screenHeight = 720;

void InitRender()
{
    InitWindow(screenWidth, screenHeight, "StarAttack Render Window | 3D Scene");
    DisableCursor();
    SetTargetFPS(60);

    InitPlayer(0, 1, 0);
}

void StartRender()
{
    while(WindowShouldClose() == false)
    {
        UpdatePlayer();

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            BeginMode3D(GetPlayerCamera());
            {
                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, BLACK);
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD); 
            }
            EndMode3D();
        }
        EndDrawing();
    }

    CloseWindow();
}