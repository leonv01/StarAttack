#ifndef __SA_SETTINGS_H
#define __SA_SETTINGS_H

#include <stdbool.h>

/* ------------------------------ General flags ----------------------------- */
static bool settingsUpdated = false;
/* -------------------------------------------------------------------------- */

/* ---------------------------- Screen attributes --------------------------- */
static float SCREEN_RATIO = 16.0f / 9.0f;
static int SCREEN_WIDTH = 1920;
static int SCREEN_HEIGHT = 1080;
static int GAME_FPS = 60;
static bool FULLSCREEN_ACTIVE = false;
/* -------------------------------------------------------------------------- */

/* --------------------------- Control attributes --------------------------- */
static bool toggleCrouch = false;
/* -------------------------------------------------------------------------- */

#endif // __SA_SETTINGS_H