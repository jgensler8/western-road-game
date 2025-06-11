#pragma bank 3
#include "scene_inn.h"
#include "animate.h"
#include "character.h"

uint8_t is_talking = 0;
uint8_t talking_changed = 0;
static void process_input(void)
{
    if (joypad_a_pressed)
    {
        is_talking = !is_talking;
        talking_changed = 1;
    }
}

static void render(uint8_t swapped)
{
    if (swapped)
    {
        // character_init(CHARACTER_MODEL_STORE_OWNER, 1, 1);
        character_init(CHARACTER_MODEL_CHERI, 1, 1);
        // frame
        draw_frame(0, 0, 10, 10);
        text_draw_frame("HELLO THERE", EMPTY);
    }
    else
    {
        // character_render(CHARACTER_MODEL_STORE_OWNER, CHARACTER_EXPRESSION_DEFAULT);
        character_render(CHARACTER_MODEL_CHERI, CHARACTER_EXPRESSION_DEFAULT);
    }
    talking_changed = 0;
}
BANKREF(scene_inn_ref)
struct Scene scene_inn = {
    .process_input = process_input,
    .render = render,
};