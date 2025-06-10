#pragma bank 0
#include "gen_scene_inn.h"

static uint8_t progress;
static uint8_t progress_changed;
static struct ProgressableFrame frame;

struct Menu menu_11 = {
    .options = {
        "SURE IS",
        "YOU BETCHA"
    },
    .max_option = 2,
};

struct Menu menu_2 = {
    .options = {
        "HEADED HOME",
        "ON A VACATION"
    },
    .max_option = 2,
};

struct Menu menu_6 = {
    .options = {
        "SHOP",
        "CUSTOMERS"
    },
    .max_option = 2,
};
#include "scene_shop.h"
BANKREF_EXTERN(scene_shop_ref)
#include "gen_scene_customers.h"
BANKREF_EXTERN(gen_scene_customers_ref)


static void process_input(void) {
    switch(progress){
            case 0:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 1;
                progress_changed = 1;
            }
        }
        break;
    case 1:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 2;
                progress_changed = 1;
            }
        }
        break;
    case 4:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 7;
                progress_changed = 1;
            }
        }
        break;
    case 7:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 11;
                progress_changed = 1;
            }
        }
        break;
    case 14:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 13;
                progress_changed = 1;
            }
        }
        break;
    case 15:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 13;
                progress_changed = 1;
            }
        }
        break;
    case 11:
        if(menu_process_input(&menu_11))
        {
            switch(menu_11.selection)
            {
            case 0:
                
                progress = 14;
                break;
            case 1:
                
                progress = 15;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
        }
        break;
    case 13:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 3;
                progress_changed = 1;
            }
        }
        break;
    case 5:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 8;
                progress_changed = 1;
            }
        }
        break;
    case 8:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 12;
                progress_changed = 1;
            }
        }
        break;
    case 12:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 3;
                progress_changed = 1;
            }
        }
        break;
    case 2:
        if(menu_process_input(&menu_2))
        {
            switch(menu_2.selection)
            {
            case 0:
                
                progress = 4;
                break;
            case 1:
                
                progress = 5;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
        }
        break;
    case 3:
        if(joypad_a_pressed)
        {
            
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 6;
                progress_changed = 1;
            }
        }
        break;
    case 9:
        if(joypad_a_pressed)
        {
            queue_scene(&scene_shop, BANK(scene_shop_ref));
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 254;
                progress_changed = 1;
            }
        }
        break;
    case 10:
        if(joypad_a_pressed)
        {
            queue_scene(&gen_scene_customers, BANK(gen_scene_customers_ref));
            if(text_frame_has_progress(&frame) && !frame.fast_forward)
            {
                frame.fast_forward = 1;
            } else {
                progress = 254;
                progress_changed = 1;
            }
        }
        break;
    case 6:
        if(menu_process_input(&menu_6))
        {
            switch(menu_6.selection)
            {
            case 0:
                queue_scene(&scene_shop, BANK(scene_shop_ref));
                progress = 9;
                break;
            case 1:
                queue_scene(&gen_scene_customers, BANK(gen_scene_customers_ref));
                progress = 10;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
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
            text_progress_init("HELLO THERE", "TRAVELER", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("WHERE ARE YOU", "HEADED?", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 4:
        if(progress_changed) {
            text_progress_init("HEADED HOME", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("IS THAT SO?", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 14:
        if(progress_changed) {
            text_progress_init("SURE IS", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 15:
        if(progress_changed) {
            text_progress_init("YOU BETCHA", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 11:
        menu_render(&menu_11);
        break;
    case 13:
        if(progress_changed) {
            text_progress_init("WELL, ITS A LONG", "ROAD...", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("ON A VACATION", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("OUT HERE?", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 12:
        if(progress_changed) {
            text_progress_init("WELL, TO EACH", "THERE OWN", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 2:
        menu_render(&menu_2);
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("ANYWAY, WHAT CAN I", "DO FOR YOU?", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 9:
        if(progress_changed) {
            text_progress_init("SHOP", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("CUSTOMERS", "", &frame);
        }
        text_draw_frame_progress(&frame);
        break;
    case 6:
        menu_render(&menu_6);
        break;

    }
    progress_changed = 0;
}

BANKREF(gen_scene_inn_ref)
struct Scene gen_scene_inn =
{
    .process_input = process_input,
    .render = render,
};
