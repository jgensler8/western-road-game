#pragma bank 7
#include "gen_scene_blue_house.h"

static uint8_t progress;
static uint8_t progress_changed;
static uint8_t code_ready = 1;
static struct ProgressableFrame frame;

static struct Menu menu_4 = {
    .options = {
        "I DON'T THINK SO",
        "YOU SEEM FAMILIAR"
    },
    .max_option = 1,
};

static struct Menu menu_11 = {
    .options = {
        "WHY DO YOU LIVE",
        "ANY QUESTS?"
    },
    .max_option = 1,
};
#include "scene_road.h"
BANKREF_EXTERN(scene_road_ref)


static void process_input(void) {
    uint8_t local_joypad_a_pressed = joypad_a_pressed;
    switch(progress){
            case 0:
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(STAT(VERONICA_VISITS)>=1&&default_state.quest!=QUEST_VERONICA_QUEST_1) {
            if(1){
                progress = 30;
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
        if(default_state.quest==QUEST_VERONICA_QUEST_1) {
            if(1){
                progress = 36;
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
    case 15:
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
                    progress = 37;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 37;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 37:
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
                    progress = 39;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 39;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 39:
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
                    progress = 41;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 41;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 41:
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
                    progress = 43;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 43;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 43:
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
    case 16:
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
        if(code_ready != 0) { ADDITEM(BLUE_PACKAGE); if(QUEST_VERONICA_QUEST_1 != QUEST_NONE) { default_state.quest = QUEST_VERONICA_QUEST_1; } code_ready = 0; }
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
    case 11:
        if(menu_process_input(&menu_11))
        {
            switch(menu_11.selection)
            {
            case 0:
                
                progress = 15;
                break;
            case 1:
                
                progress = 16;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
        }
        break;
    case 14:
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(1){
                progress = 52;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(1){
                progress = 16;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 36;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 36;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 36:
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
                    progress = 38;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 38;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 38:
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
                    progress = 40;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 40;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 40:
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
                    progress = 42;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 42;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 42:
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
                    progress = 44;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 44;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 44:
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
                    progress = 45;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 45;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 45:
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
                    progress = 46;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 46;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 46:
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(1) {
            if(1){
                progress = 52;
                progress_changed = 1;
                code_ready = 1;
            }
            if(local_joypad_a_pressed)
            {
                
                if(text_frame_has_progress(&frame) && !frame.fast_forward)
                {
                    frame.fast_forward = 1;
                } else {
                    progress = 47;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 47;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 47:
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
                    progress = 48;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 48;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 48:
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
                    progress = 49;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 49;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 49:
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
                    progress = 50;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 50;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 50:
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
                    progress = 51;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 51;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 51:
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
                    progress = 52;
                    progress_changed = 1;
                    code_ready = 1;
                }
            }
        } else {
            progress = 52;
            progress_changed = 1;
            code_ready = 1;
        }
        break;
    case 52:
        if(code_ready != 0) { INCR(VERONICA_VISITS); if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
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
    if(options->swapped){ character_init(CHARACTER_MODEL_VERONICA,1,1); progress = 0; progress_changed = 1; code_ready = 1; }
    character_render(CHARACTER_MODEL_VERONICA, CHARACTER_EXPRESSION_DEFAULT);
    switch(progress)
    {
        case 0:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 1:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 2:
        if(progress_changed) {
            text_progress_init("HELLO THERE,", "TRAVELER", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("HAVE WE MET", "BEFORE?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("I DON'T THINK SO", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 9:
        if(progress_changed) {
            text_progress_init("WELL, NICE TO MEET", "YOU!", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 12:
        if(progress_changed) {
            text_progress_init("I'M VERONICA", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("YOU SEEM FAMILIAR", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("HMM...", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 13:
        if(progress_changed) {
            text_progress_init("I DON'T SEEM TO", "RECALL...", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 17:
        if(progress_changed) {
            text_progress_init("ANYWAY, I'M", "VERONICA", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 4:
        menu_render(&menu_4);
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("PLEASED TO MEET", "YOU", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("SO WHAT BRINGS YOU", "THIS WAY?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 15:
        if(progress_changed) {
            text_progress_init("WHY DO YOU LIVE", "HERE", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 19:
        if(progress_changed) {
            text_progress_init("ISN'T THIS PLACE A", "BIT REMOTE?", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 22:
        if(progress_changed) {
            text_progress_init("HAHA... IT'S EASY", "TO THINK THAT", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 25:
        if(progress_changed) {
            text_progress_init("ITS A LONGER STORY", "THAN", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 28:
        if(progress_changed) {
            text_progress_init("I'D LIKE TO ADMIT", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 31:
        if(progress_changed) {
            text_progress_init("BUT I WAS DOING", "SOME WORK OUT HERE", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 34:
        if(progress_changed) {
            text_progress_init("AND YEAR AFTER", "YEAR PASSED BY", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 37:
        if(progress_changed) {
            text_progress_init("I FIGURED...", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 39:
        if(progress_changed) {
            text_progress_init("THIS IS AS GOOD A", "PLACE AS ANY", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 41:
        if(progress_changed) {
            text_progress_init("SO WHY BOTHER", "MOVING, RIGHT?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 43:
        if(progress_changed) {
            text_progress_init("RIGHT", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 16:
        if(progress_changed) {
            text_progress_init("ANY QUESTS?", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 20:
        if(progress_changed) {
            text_progress_init("DO I HAVE A QUEST", "FOR YOU?", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 23:
        if(progress_changed) {
            text_progress_init("LET ME THINK...", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 26:
        if(progress_changed) {
            text_progress_init("SURE, BRING THIS", "ITEM TO THE SHOP", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 29:
        if(progress_changed) {
            text_progress_init("I HAVEN'T HAD TIME", "TO DO IT MYSELF", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 32:
        if(progress_changed) {
            text_progress_init("SURE, SOUNDS EASY", "ENOUGH", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 35:
        if(progress_changed) {
            text_progress_init("SHE HANDS YOU A", "BLUE PACKAGE", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 11:
        menu_render(&menu_11);
        break;
    case 14:
        if(progress_changed) {
            text_progress_init("I HAVE SOME CHORES", "TO ATTEND TO", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 18:
        if(progress_changed) {
            text_progress_init("HOPEFULLY I'LL SEE", "YOU AROUND", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 21:
        if(progress_changed) {
            text_progress_init("TAKE CARE", "VERONICA!", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 24:
        if(progress_changed) {
            text_progress_init("SEE YOU!", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 27:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 30:
        if(progress_changed) {
            text_progress_init("HELLO AGAIN!", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 33:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 36:
        if(progress_changed) {
            text_progress_init("HMM SEEMS YOU", "HAVEN'T", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 38:
        if(progress_changed) {
            text_progress_init("DELIVERED THE", "PACKAGE", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 40:
        if(progress_changed) {
            text_progress_init("SHE HANDS YOU A", "BLUE PACKAGE", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 42:
        if(progress_changed) {
            text_progress_init("HERE IS ANOTHER", "ONE", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 44:
        if(progress_changed) {
            text_progress_init("AND DON'T LOSE", "THIS ONE!", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 45:
        if(progress_changed) {
            text_progress_init("UHH... SURE!", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 46:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 47:
        if(progress_changed) {
            text_progress_init("THANK YOU FOR", "DELIVERING IT!", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 48:
        if(progress_changed) {
            text_progress_init("SORRY, LOOKS LIKE", "I'VE", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 49:
        if(progress_changed) {
            text_progress_init("RUN OUT OF THINGS", "TO", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 50:
        if(progress_changed) {
            text_progress_init("TALK ABOUT", "", &frame);
            character_start_talking(CHARACTER_MODEL_VERONICA);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_VERONICA);
        };
        break;
    case 51:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 52:
        if(progress_changed) {
            text_progress_init("YOU HEAD BACK", "", &frame);
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
