#pragma bank 3
#include "gen_scene_customers.h"

static uint8_t progress;
static uint8_t progress_changed;
static uint8_t code_ready = 1;
static struct ProgressableFrame frame;

static struct Menu menu_5 = {
    .options = {
        "SURE",
        "NO, I'M FINE"
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
    case 4:
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
    case 13:
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
                    progress = 17;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 17;
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
                    progress = 19;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 19;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 19:
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
                    progress = 21;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 21;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 21:
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
                    progress = 6;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 6;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 8:
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
                    progress = 16;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 16;
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
                    progress = 18;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 18;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 18:
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
                    progress = 20;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 20;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 20:
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
                    progress = 6;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 6;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 5:
        if(menu_process_input(&menu_5))
        {
            switch(menu_5.selection)
            {
            case 0:
                
                progress = 7;
                break;
            case 1:
                
                progress = 8;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
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
    if(options->swapped){ character_init(CHARACTER_MODEL_CHERI,1,1); progress = 0; progress_changed = 1; code_ready = 1; }
    character_render(CHARACTER_MODEL_CHERI, CHARACTER_EXPRESSION_DEFAULT);
    switch(progress)
    {
        case 0:
        if(progress_changed) {
            text_progress_init("HEY THERE!", "", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("YOU MUST BE NEW", "AROUND HERE", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 2:
        if(progress_changed) {
            text_progress_init("I'M CHERI, I DON'T", "BELIEVE WE'VE MET", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("NICE TO MEET YOU,", "CHERI", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 4:
        if(progress_changed) {
            text_progress_init("SAY, DO YOU WANT", "TO KNOW A SECRET?", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("SURE", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 9:
        if(progress_changed) {
            text_progress_init("SO HEAD DOWN A BIT", "FURTHER", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 11:
        if(progress_changed) {
            text_progress_init("MAYBE 100 STEPS OR", "SO", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 13:
        if(progress_changed) {
            text_progress_init("ON THE RIGHT, YOU", "SHOULD SEE", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 15:
        if(progress_changed) {
            text_progress_init("A SMALL SHED", "", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 17:
        if(progress_changed) {
            text_progress_init("IT SHOULD BE OFF", "THE ROAD", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 19:
        if(progress_changed) {
            text_progress_init("DID YOU GET ALL", "THAT?", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 21:
        if(progress_changed) {
            text_progress_init("UHM... SURE!", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("NO, I'M FINE", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("REALLY? AWW...", "", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 12:
        if(progress_changed) {
            text_progress_init("I WAS REALLY", "HOPING", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 14:
        if(progress_changed) {
            text_progress_init("TO TELL SOMEONE", "", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 16:
        if(progress_changed) {
            text_progress_init("GUESS I'LL SAVE", "THAT", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 18:
        if(progress_changed) {
            text_progress_init("FOR ANOTHER DAY", "", &frame);
            character_start_talking(CHARACTER_MODEL_CHERI);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_CHERI);
        };
        break;
    case 20:
        if(progress_changed) {
            text_progress_init("UHM... OK...", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 5:
        menu_render(&menu_5);
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("TIME TO HIT THE", "ROAD", &frame);
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

BANKREF(gen_scene_customers_ref)
struct Scene gen_scene_customers =
{
    .process_input = process_input,
    .render = render,
};
