#pragma bank 4
#include "gen_scene_shack.h"

static uint8_t progress;
static uint8_t progress_changed;
static uint8_t code_ready = 1;
static struct ProgressableFrame frame;

static struct Menu menu_4 = {
    .options = {
        "LEAVE",
        "EXPLORE"
    },
    .max_option = 1,
};
#include "scene_road.h"
BANKREF_EXTERN(scene_road_ref)


static void process_input(void) {
    switch(progress){
            case 0:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
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
        if(1) {
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
        if(1) {
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
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 12;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 12;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 12:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(joypad_a_pressed)
            {
                queue_scene(&scene_road, BANK(scene_road_ref));
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
    case 13:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
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
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
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
    case 8:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 11;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 11;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 11:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
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
    case 15:
        if(code_ready != 0) { ; code_ready = 0; }
        if(1) {
            if(joypad_a_pressed)
            {
                queue_scene(&scene_road, BANK(scene_road_ref));
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

    }
}

static void render(const struct SceneRenderOptions* options) {
    if(options->swapped){  progress = 0; progress_changed = 1; code_ready = 1; }
    
    switch(progress)
    {
        case 0:
        if(progress_changed) {
            text_progress_init("OH, THIS MUST BE", "WHAT", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("CHERI WAS TALKING", "ABOUT", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 2:
        if(progress_changed) {
            text_progress_init("YOU TAKE A STEP", "TOWARD THE SHACK", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("YOU HEAR A WEIRD", "HUMMING SOUND", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("LEAVE", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 9:
        if(progress_changed) {
            text_progress_init("NO WAY I AM GOING", "FURTHER", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 12:
        if(progress_changed) {
            text_progress_init("YOU DEPART", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("EXPLORE", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("THAT'S A BIT ODD", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 13:
        if(progress_changed) {
            text_progress_init("BETTER CHECK IT", "OUT!", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 4:
        menu_render(&menu_4);
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("WHAT IS THIS?", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("YOU OPEN THE", "DOOR...", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 11:
        if(progress_changed) {
            text_progress_init("IT'S THE SOURCE OF", "THE BUZZING", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 14:
        if(progress_changed) {
            text_progress_init("LOOKS LIKE AN OLD", "RADIO", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 15:
        if(progress_changed) {
            text_progress_init("I'LL TAKE THIS", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;

    }
    progress_changed = 0;
}

BANKREF(gen_scene_shack_ref)
struct Scene gen_scene_shack =
{
    .process_input = process_input,
    .render = render,
};
