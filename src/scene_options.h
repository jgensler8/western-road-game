#pragma once
#include "scene_common.h"

extern uint16_t scene_options_swapped;
extern uint16_t scene_options_takeover;
#define SCENE_OPTIONS_INIT     \
    scene_options_swapped = 0; \
    scene_options_takeover = 0;
#define SCENE_OPTIONS_PROCESS_INPUT_TAKEOVER                       \
    if (scene_options_takeover == 0 && joypad_start_pressed)       \
    {                                                              \
        scene_options_swapped = 1;                                 \
        scene_options_takeover = 1;                                \
        return;                                                    \
    }                                                              \
    if (scene_options_takeover == 1 && scene_options_swapped == 0) \
    {                                                              \
        scene_options.process_input();                             \
        return;                                                    \
    }
#define SCENE_OPTIONS_RENDER_TAKEOVER \
    if (scene_options_takeover)       \
    {                                 \
        scene_options.render(NULL);   \
        return;                       \
    }
extern struct Scene scene_options;