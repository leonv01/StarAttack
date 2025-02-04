#include "render.h"

#include <raylib.h>

#include "../../entity/player/player.h"

// TODO: Change to load screen config from file
static int screenWidth = 1920;
static int screenHeight = 1080;

void InitRender()
{
    InitWindow(screenWidth, screenHeight, "StarAttack Render Window | 3D Scene");
    DisableCursor();
    SetTargetFPS(60);

    InitPlayer(4, 2, 4);
}

void StartRender()
{
    Model model = LoadModel("resources/mesh/player/Skeleton.glb");

    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

    Vector3 modelPosition = (Vector3){ 0, 0, 0 };

    while(WindowShouldClose() == false)
    {
        UpdatePlayer();

        BeginDrawing();
        {
            ClearBackground(BLACK);
            BeginMode3D(GetPlayerCamera());
            {
                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, ORANGE);
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD); 
            }
            DrawModel(model, modelPosition, 1.0f, WHITE);
            EndMode3D();
        }
        EndDrawing();
    }

    CloseWindow();
}