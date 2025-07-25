#pragma bank 8
#include "scene_bandit.h"

uint8_t talking = 0;
static void process_input(void)
{
    if (joypad_a_pressed)
    {
        if (talking == 0)
        {
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
            talking = 1;
        }
        else
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
            talking = 0;
        }
    }
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        character_init(CHARACTER_MODEL_BANDIT_A, 1, 1);
        text_draw_frame("HALT!", EMPTY);
    }
    character_render(CHARACTER_MODEL_BANDIT_A, CHARACTER_EXPRESSION_DEFAULT);
}

BANKREF(scene_bandit_ref)
struct Scene scene_bandit = {
    .process_input = process_input,
    .render = render,
};