#pragma bank 0
#include "scene_dialog.h"

static uint8_t progress;
static char **dialogs;
static uint8_t dialog_count;
static struct Scene *next_scene;
static uint8_t next_bank_num;
void scene_dialog_init(char **new_dialogs, uint8_t new_dialog_count, struct Scene *new_next_scene, uint8_t new_bank_num)
{
    dialogs = new_dialogs;
    dialog_count = new_dialog_count;
    next_scene = new_next_scene;
    next_bank_num = new_bank_num;
}
void scene_dialog_process_input(void)
{
    if (progress < dialog_count)
    {
        if (joypad_a_pressed)
        {
            play_sfx_high();
            progress++;
        }
    }
    else
    {
        queue_scene(next_scene, next_bank_num);
    }
}
static uint8_t last_render_progress;
static struct ProgressableFrame frame;
void scene_dialog_render(uint8_t swapped)
{
    if (swapped)
    {
        progress = 0;
        last_render_progress = 0xff;
    }
    if (progress != last_render_progress)
    {
        last_render_progress = progress;
        if (progress < dialog_count)
        {
            text_progress_init(dialogs[progress * 2], dialogs[progress * 2 + 1], &frame);
        }
    }
    text_draw_frame_progress(&frame);
}
