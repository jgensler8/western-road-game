
#include "gen_scene_inn.h"

static uint8_t progress;

static void process_input(void) {
    
if(progress == 0)
{
    if(input_joycon_a_pressed)
    {
        progress = 1;
    }
}

if(progress == 1)
{
    if(input_joycon_a_pressed)
    {
        progress = 2;
    }
}

if(progress == 2)
{
    switch(menu_process_input(menu_2))
    {
    case 0:
        progress = 0;
        break;
    case 1:
        progress = 1;
        break;
    }
}

if(progress == 3)
{
    if(input_joycon_a_pressed)
    {
        progress = 4;
    }
}

if(progress == 4)
{
    switch(menu_process_input(menu_4))
    {
    case 0:
        progress = 0;
        break;
    case 1:
        progress = 1;
        break;
    }
}

}

static void render(uint8_t swapped) {
    if(swapped){ progress = 0; }
    
if(progress == 0)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

if(progress == 1)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

if(progress == 3)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

}

struct Scene gen_scene_inn =
{
    .process_input = process_input,
    .render = render,
};
