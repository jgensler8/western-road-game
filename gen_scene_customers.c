#pragma bank 0
#include "gen_scene_customers.h"

static uint8_t progress;
static uint8_t progress_changed;
static struct ProgressableFrame frame;


static void process_input(void) {
    switch(progress){
            case 0:
        if(joypad_a_pressed)
        {
            progress = 1;
            progress_changed = 1;
        }
        break;
    case 1:
        if(joypad_a_pressed)
        {
            progress = 2;
            progress_changed = 1;
        }
        break;
    case 2:
        if(joypad_a_pressed)
        {
            progress = 3;
            progress_changed = 1;
        }
        break;
    case 3:
        if(joypad_a_pressed)
        {
            progress = 4;
            progress_changed = 1;
        }
        break;
    case 4:
        if(joypad_a_pressed)
        {
            progress = 5;
            progress_changed = 1;
        }
        break;
    case 5:
        if(joypad_a_pressed)
        {
            progress = 6;
            progress_changed = 1;
        }
        break;
    case 6:
        if(joypad_a_pressed)
        {
            progress = 7;
            progress_changed = 1;
        }
        break;
    case 7:
        if(joypad_a_pressed)
        {
            progress = 8;
            progress_changed = 1;
        }
        break;
    case 8:
        if(joypad_a_pressed)
        {
            progress = 9;
            progress_changed = 1;
        }
        break;
    case 9:
        if(joypad_a_pressed)
        {
            progress = 10;
            progress_changed = 1;
        }
        break;
    case 10:
        if(joypad_a_pressed)
        {
            progress = 11;
            progress_changed = 1;
        }
        break;
    case 11:
        if(joypad_a_pressed)
        {
            progress = 254;
            progress_changed = 1;
        }
        break;

    }
}

static void render(uint8_t swapped) {
    if(swapped){ progress = 0; progress_changed = 1; }
    switch(progress)
    {
        case 0:
        if(progress_changed) {
            text_progress_init("YOU WAKE UP", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("WHAT'S THIS? OH, A", "PIECE OF PAPER", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 2:
        if(progress_changed) {
            text_progress_init("HERE, TAKE THIS", "MONEY", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("I HAVE A PRESENT", "WAITING FOR YOU", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 4:
        if(progress_changed) {
            text_progress_init("ITS AT THE END OF", "THE PATH", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("THE END OF THE", "PATH?", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("BUT, I DON'T EVEN", "KNOW WHERE I AM...", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("...", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("IF I DON'T KNOW", "WHY I'M HERE...", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 9:
        if(progress_changed) {
            text_progress_init("THEN I DON'T", "REALLY HAVE MUCH", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("OF A CHOICE", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 11:
        if(progress_changed) {
            text_progress_init("YOU OPEN THE DOOR", "AND EMBARK", &frame);
        }
        text_draw_frame_progress(&frame);
        break;

    }
    progress_changed = 0;
}

BANKREF(gen_scene_customers_ref)
struct Scene gen_scene_customers =
{
    .process_input = process_input,
    .render = render,
};
