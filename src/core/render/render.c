#include "render.h"

#include <raylib.h>
#include <stdio.h>

#include "../../entity/player/player.h"

// TODO: Change to load screen config from file
static int screenWidth = 2560;
static int screenHeight = 1440;

void InitRender()
{
    InitWindow(screenWidth, screenHeight, "StarAttack Render Window | 3D Scene");
    DisableCursor();
    SetTargetFPS(60);
    ToggleFullscreen();
    InitPlayer(4, 0, 4);
}

void StartRender()
{
    Model model = LoadModel("resources/mesh/player/Skeleton.glb");

    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

    Vector3 modelPosition = (Vector3){ 0, 0, 0 };

    Ray ray = { 0 };

    const Vector2 screenCenter = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };

    while(WindowShouldClose() == false)
    {
        UpdatePlayer();

        RayCollision collision = { 0 };
        char *hitObjectName = "None";
        collision.distance = 2;
        collision.hit = false;

        ray = GetScreenToWorldRay(screenCenter, GetPlayerCamera());

        RayCollision skeletonHit = GetRayCollisionBox(ray, bounds);

        bool drawBounding = false;
        if((skeletonHit.hit) && (skeletonHit.distance < collision.distance))
        {
            DrawText("Skeleton", 10, 40, 22, GREEN);
            drawBounding = true;
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);
            BeginMode3D(GetPlayerCamera());
            {
                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, ORANGE);
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD); 
                if(drawBounding)
                {
                    DrawBoundingBox(bounds, LIME);
                }
            }
            DrawModel(model, modelPosition, 1.0f, WHITE);
            EndMode3D();
        }
        DrawFPS(10, 10);
        DrawCircle(screenCenter.x, screenCenter.y, 5, LIME);
        EndDrawing();
    }

    UnloadModel(model);

    CloseWindow();
}