#include "player.h"

#include <raylib.h>

#include <stdio.h>
#include <math.h>

typedef struct Hand_t
{
    Vector3 position;
} Hand_t;

typedef struct Player_t
{
    Camera3D camera;
    float walkSpeed;
    float runFactor;
    float mouseSensivity;

    float playerHeight;

    void (*usePrimary)(void);
    void (*useSecondary)(void);
} Player_t;

static Player_t player;

static void primaryAction(void);
static void secondaryAction(void);

void InitPlayer(float x, float y, float z)
{
    player = (Player_t){ 0 };
    player.walkSpeed = 0.1f;
    player.runFactor = 2.0f;
    player.mouseSensivity = 0.2f;
    player.usePrimary = primaryAction;
    player.useSecondary = secondaryAction;
    player.playerHeight = 1.80f;

    Camera3D camera = (Camera){ 0 };
    camera.position = (Vector3){ x, y, player.playerHeight + z };    // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;

    player.camera = camera;
}

void UpdatePlayer(void)
{
    const float mouseSensitivy = player.mouseSensivity;
    float speed = player.walkSpeed;
    if(IsKeyDown(KEY_LEFT_SHIFT))
    {
        speed *= player.runFactor;
    }

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if(player.usePrimary)
        {
            player.usePrimary();
        }
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        if(player.useSecondary)
        {
            player.useSecondary();
        }
    }

    UpdateCameraPro(&player.camera,
    (Vector3)
    {
        (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) * speed -
        (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) * speed,
        (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) * speed -
        (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) * speed
    },
    (Vector3)
    {
        GetMouseDelta().x * mouseSensitivy,
        GetMouseDelta().y * mouseSensitivy,
    },
    GetMouseWheelMove() * 2.0f);
}

Camera3D GetPlayerCamera()
{
    return player.camera;
}

static void primaryAction(void)
{
    printf("Primary\n");
}

static void secondaryAction(void)
{
    printf("Secondary\n");
}