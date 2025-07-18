#pragma bank 6
#include "scene_road_fork.h"
#include "scene_road.h"
BANKREF_EXTERN(scene_road_ref)

static struct Menu left_right_choice = {
    .options = {
        "LEFT",
        "RIGHT",
    },
    .max_option = 1,
};

static void process_input(void)
{
    if (menu_process_input(&left_right_choice))
    {
        switch (left_right_choice.selection)
        {
        case 0:
            default_state.stats[STAT_RIGHT_PATH] += 1;
            break;
        case 1:
            default_state.stats[STAT_LEFT_PATH] += 1;
            break;
        }
        queue_scene(&scene_road, BANK(scene_road_ref));
    }
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        menu_reset_state();
    }
    menu_render(&left_right_choice);
}

BANKREF(scene_road_fork_ref)
struct Scene scene_road_fork = {
    .process_input = process_input,
    .render = render,
};