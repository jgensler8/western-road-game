
#include "gen_scene_customers.h"

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
    if(input_joycon_a_pressed)
    {
        progress = 3;
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
    if(input_joycon_a_pressed)
    {
        progress = 5;
    }
}

if(progress == 5)
{
    switch(menu_process_input(menu_5))
    {
    case 0:
        progress = 0;
        break;
    case 1:
        progress = 1;
        break;
    }
}

if(progress == 6)
{
    if(input_joycon_a_pressed)
    {
        progress = 7;
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

if(progress == 2)
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

if(progress == 4)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

if(progress == 6)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

}

struct Scene gen_scene_customers =
{
    .process_input = process_input,
    .render = render,
};
