#pragma bank 2
#include "scene_intro_dialog.h"
#include "scene_dialog.h"
#include "scene_road.h"

#define DIALOGS 5
static char *dialogs[DIALOGS * 2] = {
    "YOU FEEL",
    EMPTY,
    "PRETTY WEIRD",
    EMPTY,
    "JUST WOKE UP",
    EMPTY,
    "TIME TO GET OUT",
    "OF BED!",
    "DONE",
    EMPTY,
};
BANKREF_EXTERN(scene_road_ref)
static void render(uint8_t swapped)
{
    if (swapped)
    {
        scene_dialog_init(dialogs, DIALOGS, &scene_road, BANK(scene_road_ref));
    }
    scene_dialog_render(swapped);
}
BANKREF(scene_story_ref)
struct Scene scene_story = {
    .process_input = scene_dialog_process_input,
    .render = render,
};