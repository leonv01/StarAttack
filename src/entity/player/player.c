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
    float runSpeedFactor;
    float crouchSpeedFactor;
    float mouseSensivity;

    float playerHeight;
    float crouchHeight;
    float crouchTransitionFactor;

    void (*usePrimary)(void);
    void (*useSecondary)(void);
} Player_t;

static Player_t player;

static void primaryAction(void);
static void secondaryAction(void);

void InitPlayer(float x, float y, float z)
{
    player = (Player_t){ 0 };
    player.usePrimary = primaryAction;
    player.useSecondary = secondaryAction;

    player.walkSpeed = 0.1f;
    player.runSpeedFactor = 1.7f;
    player.crouchSpeedFactor = 0.25f;
    player.mouseSensivity = 0.2f;
    player.playerHeight = 1.80f;
    player.crouchHeight = 1.00f;
    player.crouchTransitionFactor = 0.075f;

    Camera3D camera = (Camera){ 0 };
    camera.position = (Vector3){ x, player.playerHeight + y, z };    // Camera position
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
        speed *= player.runSpeedFactor;
    }

    static float currentHeight = 0.0f;
    static float targetHeight = 0.0f;

    if(IsKeyDown(KEY_LEFT_CONTROL))
    {
        targetHeight = player.crouchHeight;
        speed = player.walkSpeed * player.crouchSpeedFactor;
    }
    else
    {
        targetHeight = player.playerHeight;
    }

    if(fabs(currentHeight - targetHeight) > player.crouchTransitionFactor)
    {
        if(currentHeight < targetHeight)
        {
            currentHeight += player.crouchTransitionFactor;
            if(currentHeight > targetHeight)
            {
                currentHeight = targetHeight;
            }
        }
        else
        {
            currentHeight -= player.crouchTransitionFactor;
            if(currentHeight < targetHeight)
            {
                currentHeight = targetHeight;
            }
        }
    }
    else
    {
        currentHeight = targetHeight;
    }

    player.camera.position.y = currentHeight;

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