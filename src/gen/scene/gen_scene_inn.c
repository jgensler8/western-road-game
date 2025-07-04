#pragma bank 3
#include "gen_scene_inn.h"

static uint8_t progress;
static uint8_t progress_changed;
static uint8_t code_ready = 1;
static struct ProgressableFrame frame;

static struct Menu menu_13 = {
    .options = {
        "SURE IS",
        "YOU BETCHA"
    },
    .max_option = 1,
};

static struct Menu menu_4 = {
    .options = {
        "HEADED HOME",
        "ON A VACATION"
    },
    .max_option = 1,
};

static struct Menu menu_8 = {
    .options = {
        "SHOP",
        "CUSTOMERS"
    },
    .max_option = 1,
};
#include "scene_shop.h"
BANKREF_EXTERN(scene_shop_ref)
#include "gen_scene_customers.h"
BANKREF_EXTERN(gen_scene_customers_ref)


static void process_input(void) {
    switch(progress){
            case 0:
        if(code_ready != 0) { ; code_ready = 0; }
        if(default_state.inn_visits==0) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 1;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 1;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 1:
        if(code_ready != 0) { ; code_ready = 0; }
        if(default_state.inn_visits>0) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 2;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 2;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 2:
        if(code_ready != 0) { ; code_ready = 0; }
        if(default_state.inn_visits>0) {
            if(1){
                progress = 5;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 3;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 3;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 3:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 4;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 4;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 6:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 9;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 9;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 9:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 13;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 13;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 16:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 15;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 15;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 17:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 15;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 15;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 13:
        if(menu_process_input(&menu_13))
        {
            switch(menu_13.selection)
            {
            case 0:
                
                progress = 16;
                break;
            case 1:
                
                progress = 17;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
        }
        break;
    case 15:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 5;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 5;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 7:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 10;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 10;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 10:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 14;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 14;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 14:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 5;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 5;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 4:
        if(menu_process_input(&menu_4))
        {
            switch(menu_4.selection)
            {
            case 0:
                
                progress = 6;
                break;
            case 1:
                
                progress = 7;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
        }
        break;
    case 5:
        if(code_ready != 0) { default_state.inn_visits+=1; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 8;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 8;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 11:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                queue_scene(&scene_shop, BANK(scene_shop_ref));
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 254;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 254;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 12:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(joypad_a_pressed)
            {
                queue_scene(&gen_scene_customers, BANK(gen_scene_customers_ref));
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 254;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 254;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 8:
        if(menu_process_input(&menu_8))
        {
            switch(menu_8.selection)
            {
            case 0:
                queue_scene(&scene_shop, BANK(scene_shop_ref));
                progress = 11;
                break;
            case 1:
                queue_scene(&gen_scene_customers, BANK(gen_scene_customers_ref));
                progress = 12;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
        }
        break;

    }
}

static void render(const struct SceneRenderOptions* options) {
    if(options->swapped){ character_init(CHARACTER_MODEL_STORE_OWNER,1,1); progress = 0; progress_changed = 1; code_ready = 1; }
    character_render(CHARACTER_MODEL_STORE_OWNER, CHARACTER_EXPRESSION_DEFAULT);
    switch(progress)
    {
        case 0:
        if(progress_changed) {
            text_progress_init("HELLO THERE", "TRAVELER", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("WE MEET AGAIN", "", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 2:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("WHERE ARE YOU", "HEADED?", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("HEADED HOME", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 9:
        if(progress_changed) {
            text_progress_init("IS THAT SO?", "", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 16:
        if(progress_changed) {
            text_progress_init("SURE IS", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 17:
        if(progress_changed) {
            text_progress_init("YOU BETCHA", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 13:
        menu_render(&menu_13);
        break;
    case 15:
        if(progress_changed) {
            text_progress_init("WELL, ITS A LONG", "ROAD...", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("ON A VACATION", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("OUT HERE?", "", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 14:
        if(progress_changed) {
            text_progress_init("WELL, TO EACH", "THERE OWN", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 4:
        menu_render(&menu_4);
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("ANYWAY, WHAT CAN I", "DO FOR YOU?", &frame);
            character_start_talking(CHARACTER_MODEL_STORE_OWNER);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_STORE_OWNER);
        };
        break;
    case 11:
        if(progress_changed) {
            text_progress_init("SHOP", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 12:
        if(progress_changed) {
            text_progress_init("CUSTOMERS", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 8:
        menu_render(&menu_8);
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
