#pragma bank 2
#include "gen_scene_intro.h"

static uint8_t progress;
static uint8_t progress_changed;
static uint8_t code_ready = 1;
static struct ProgressableFrame frame;
#include "scene_road.h"
BANKREF_EXTERN(scene_road_ref)


static void process_input(void) {
    uint8_t local_joypad_a_pressed = joypad_a_pressed;
    switch(progress){
            case 0:
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
    case 5:
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(0){
                progress = 254;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
            text_progress_init("YOU WAKE UP", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("WHAT'S THIS? OH, A", "PIECE OF PAPER", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 2:
        if(progress_changed) {
            text_progress_init("\"HERE, TAKE THIS", "MONEY\"", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("\"I HAVE A PRESENT", "WAITING FOR YOU\"", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 4:
        if(progress_changed) {
            text_progress_init("\"ITS AT THE END", "OF THE PATH\"", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("THE END OF THE", "PATH?", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("THE PATH CAN'T BE", "THAT LONG", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("LET'S TAKE A", "LOOK...", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("YOU OPEN THE DOOR", "", &frame);
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

BANKREF(gen_scene_intro_ref)
struct Scene gen_scene_intro =
{
    .process_input = process_input,
    .render = render,
};
