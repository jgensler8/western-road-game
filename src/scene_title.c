#pragma bank 2
#include "scene_title.h"
#include "scene_common.h"
#include "gen/scene/gen_scene_intro.h"

struct Menu start_menu = {
    .options = {
        "START",
        "LOAD",
    },
    .max_option = 1,
    .selection = 0,
};
BANKREF_EXTERN(gen_scene_intro_ref)
void scene_title_process_input(void)
{
    if (menu_process_input(&start_menu))
    {
        play_sfx_blip();
        switch (start_menu.selection)
        {
        case 0:
            queue_scene(&gen_scene_intro, BANK(gen_scene_intro_ref));
            break;
        case 1:
            // TODO: save/load
            // queue_scene();
            break;
        }
    }
}
void scene_title_render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        start_menu.selection = 0;
    }
    menu_render(&start_menu);
}

BANKREF(scene_title_ref)
struct Scene scene_title = {
    .process_input = scene_title_process_input,
    .render = scene_title_render,
};