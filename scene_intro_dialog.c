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
static void render(uint8_t swapped)
{
    if (swapped)
    {
        scene_dialog_init(dialogs, DIALOGS, &scene_road);
    }
    scene_dialog_render(swapped);
}
struct Scene scene_story = {
    .process_input = scene_dialog_process_input,
    .render = render,
};