#pragma bank 4
#include "gen_scene_blue_house.h"

static uint8_t progress;
static uint8_t progress_changed;
static uint8_t code_ready = 1;
static struct ProgressableFrame frame;

static struct Menu menu_2 = {
    .options = {
        "I DON'T THINK SO",
        "YOU SEEM FAMILIAR"
    },
    .max_option = 1,
};

static struct Menu menu_9 = {
    .options = {
        "WHY DO YOU LIVE",
        "ANY QUESTS?"
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
                    progress = 7;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 7;
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
    case 5:
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
                    progress = 23;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 23;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 23:
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
                    progress = 26;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 26;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 26:
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
                    progress = 28;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 28;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 28:
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
                    progress = 30;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 30;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 30:
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
                    progress = 32;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 32;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 32:
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
                    progress = 33;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 33;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 33:
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
                    progress = 34;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 34;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 34:
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
                    progress = 35;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 35;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 35:
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
                    progress = 24;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 24;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 24:
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
                    progress = 27;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 27;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 27:
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
                    progress = 29;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 29;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 29:
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
                    progress = 31;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 31;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 31:
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
    case 9:
        if(menu_process_input(&menu_9))
        {
            switch(menu_9.selection)
            {
            case 0:
                
                progress = 13;
                break;
            case 1:
                
                progress = 14;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
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
                    progress = 22;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 22;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 22:
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
                    progress = 25;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 25;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 25:
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
    if(options->swapped){ character_init(CHARACTER_MODEL_VERONICA,1,1); progress = 0; progress_changed = 1; code_ready = 1; }
    character_render(CHARACTER_MODEL_VERONICA, CHARACTER_EXPRESSION_DEFAULT);
    switch(progress)
    {
        case 0:
        if(progress_changed) {
            text_progress_init("HELLO THERE,", "TRAVELER", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("HAVE WE MET", "BEFORE?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 4:
        if(progress_changed) {
            text_progress_init("I DON'T THINK SO", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("WELL, NICE TO MEET", "YOU!", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("I'M VERONICA", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("YOU SEEM FAMILIAR", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("HMM...", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 11:
        if(progress_changed) {
            text_progress_init("I DON'T SEEM TO", "RECALL...", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 15:
        if(progress_changed) {
            text_progress_init("ANYWAY, I'M", "VERONICA", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 2:
        menu_render(&menu_2);
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("PLEASED TO MEET", "YOU", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("SO WHAT BRINGS YOU", "THIS WAY?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 13:
        if(progress_changed) {
            text_progress_init("WHY DO YOU LIVE", "HERE", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 17:
        if(progress_changed) {
            text_progress_init("ISN'T THIS PLACE A", "BIT REMOTE?", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 20:
        if(progress_changed) {
            text_progress_init("HAHA... IT'S EASY", "TO THINK THAT", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 23:
        if(progress_changed) {
            text_progress_init("ITS A LONGER STORY", "THAN", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 26:
        if(progress_changed) {
            text_progress_init("I'D LIKE TO ADMIT", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 28:
        if(progress_changed) {
            text_progress_init("BUT I WAS DOING", "SOME WORK OUT HERE", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 30:
        if(progress_changed) {
            text_progress_init("AND YEAR AFTER", "YEAR PASSED BY", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 32:
        if(progress_changed) {
            text_progress_init("I FIGURED...", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 33:
        if(progress_changed) {
            text_progress_init("THIS IS AS GOOD A", "PLACE AS ANY", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 34:
        if(progress_changed) {
            text_progress_init("SO WHY BOTHER", "MOVING, RIGHT?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 35:
        if(progress_changed) {
            text_progress_init("RIGHT", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 14:
        if(progress_changed) {
            text_progress_init("ANY QUESTS?", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 18:
        if(progress_changed) {
            text_progress_init("DO I HAVE A QUEST", "FOR YOU?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 21:
        if(progress_changed) {
            text_progress_init("LET ME THINK...", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 24:
        if(progress_changed) {
            text_progress_init("SURE, BRING THIS", "ITEM TO THE SHOP", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 27:
        if(progress_changed) {
            text_progress_init("I HAVEN'T HAD TIME", "TO DO IT MYSELF", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 29:
        if(progress_changed) {
            text_progress_init("SURE, SOUNDS EASY", "ENOUGH", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 31:
        if(progress_changed) {
            text_progress_init("SHE HANDS YOU A", "BLUE PACKAGE", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 9:
        menu_render(&menu_9);
        break;
    case 12:
        if(progress_changed) {
            text_progress_init("I HAVE SOME CHORES", "TO ATTEND TO", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 16:
        if(progress_changed) {
            text_progress_init("HOPEFULLY I'LL SEE", "YOU AROUND", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 19:
        if(progress_changed) {
            text_progress_init("TAKE CARE", "VERONICA!", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 22:
        if(progress_changed) {
            text_progress_init("SEE YOU!", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 25:
        if(progress_changed) {
            text_progress_init("YOU HEAD BACK ON", "THE ROAD", &frame);
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

BANKREF(gen_scene_blue_house_ref)
struct Scene gen_scene_blue_house =
{
    .process_input = process_input,
    .render = render,
};
