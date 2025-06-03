#include "scene_intro_dialog.h"
#include "scene_common.h"

uint8_t scene_story_dialog_progress = 0;
char *dialogs[5] = {
    "YOU FEEL",
    "PRETTY WEIRD",
    "JUST WOKE UP",
    "TIME TO GET OUT\nOF BED!",
    "DONE\n",
};
void scene_story_process_input(void)
{
    if (scene_story_dialog_progress < 4)
    {
        if (joypad_a_pressed)
        {
            play_sfx_high();
            scene_story_dialog_progress++;
        }
    }
    else
    {
        // queue_scene();
    }
}
uint8_t scene_story_last_render_progress;
struct ProgressableFrame scene_story_progressable_frame;
void scene_story_render(uint8_t swapped)
{
    if (swapped)
    {
        scene_story_dialog_progress = 0;
        scene_story_last_render_progress = 0xff;
    }
    if (scene_story_dialog_progress != scene_story_last_render_progress)
    {
        draw_frame_text(dialogs[scene_story_dialog_progress], EMPTY);
        scene_story_last_render_progress = scene_story_dialog_progress;
        frame_progress_init(dialogs[scene_story_dialog_progress], EMPTY, &scene_story_progressable_frame);
    }
    draw_frame_progress(&scene_story_progressable_frame);
}
struct Scene scene_story = {
    .process_input = scene_story_process_input,
    .render = scene_story_render,
};