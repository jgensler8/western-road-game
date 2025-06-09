
#include "gen_scene_intro.h"

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
    if(input_joycon_a_pressed)
    {
        progress = 6;
    }
}

if(progress == 6)
{
    if(input_joycon_a_pressed)
    {
        progress = 7;
    }
}

if(progress == 7)
{
    if(input_joycon_a_pressed)
    {
        progress = 8;
    }
}

if(progress == 8)
{
    if(input_joycon_a_pressed)
    {
        progress = 9;
    }
}

if(progress == 9)
{
    if(input_joycon_a_pressed)
    {
        progress = 10;
    }
}

if(progress == 10)
{
    if(input_joycon_a_pressed)
    {
        progress = 11;
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

if(progress == 5)
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

if(progress == 7)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

if(progress == 8)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

if(progress == 9)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

if(progress == 10)
{
    if(swapped) {
        text_progress_init(1, 1, &frame);
    }
    text_draw_frame_progress(&frame);
}

}

struct Scene gen_scene_intro =
{
    .process_input = process_input,
    .render = render,
};
