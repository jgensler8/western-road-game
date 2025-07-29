#pragma bank 8
#include "gen_scene_bandit.h"

static uint8_t progress;
static uint8_t progress_changed;
static uint8_t code_ready = 1;
static struct ProgressableFrame frame;

static struct Menu menu_1 = {
    .options = {
        "LET ME GO!",
        "WHAT DO YOU WANT?"
    },
    .max_option = 1,
};

static struct Menu menu_11 = {
    .options = {
        "NO! DEFINITELY NOT",
        "FINE..."
    },
    .max_option = 1,
};

static struct Menu menu_24 = {
    .options = {
        "EVEN",
        "ODD"
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
        if(STAT(GOLD)>0) {
            if(1){
                progress = 2;
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
                progress = 45;
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
            if(1){
                progress = 14;
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
    case 1:
        if(menu_process_input(&menu_1))
        {
            switch(menu_1.selection)
            {
            case 0:
                
                progress = 3;
                break;
            case 1:
                
                progress = 4;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
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
        if(code_ready != 0) { STAT(GOLD)=0; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
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
            if(1){
                progress = 45;
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
        if(code_ready != 0) { STAT(GOLD)-=1; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
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
            if(1){
                progress = 45;
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
        if(code_ready != 0) { ; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
        if(STAT(STEPS)%2==0) {
            if(1){
                progress = 28;
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
            if(1){
                progress = 41;
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
        if(STAT(STEPS)%2==1) {
            if(1){
                progress = 28;
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
            if(1){
                progress = 41;
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
    case 24:
        if(menu_process_input(&menu_24))
        {
            switch(menu_24.selection)
            {
            case 0:
                
                progress = 29;
                break;
            case 1:
                
                progress = 30;
                break;
            }
            progress_changed = 1;
            menu_reset_state();
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
            if(1){
                progress = 45;
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
        if(code_ready != 0) { STAT(GOLD)-=1; if(QUEST_NONE != QUEST_NONE) { default_state.quest = QUEST_NONE; } code_ready = 0; }
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
    if(options->swapped){ character_init(CHARACTER_MODEL_BANDIT_A,1,1); progress = 0; progress_changed = 1; code_ready = 1; }
    character_render(CHARACTER_MODEL_BANDIT_A, CHARACTER_EXPRESSION_DEFAULT);
    switch(progress)
    {
        case 0:
        if(progress_changed) {
            text_progress_init("HALT!", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 3:
        if(progress_changed) {
            text_progress_init("LET ME GO!", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 6:
        if(progress_changed) {
            text_progress_init("I DON'T THINK SO", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 9:
        if(progress_changed) {
            text_progress_init("I'VE HAD A BAD DAY", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 12:
        if(progress_changed) {
            text_progress_init("AND NOW YOU'LL", "HAVE ONE TOO", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 17:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 22:
        if(progress_changed) {
            text_progress_init("WAIT... YOU DON'T", "HAVE ANY COINS!", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 27:
        if(progress_changed) {
            text_progress_init("WHAT A WASTE OF", "TIME!", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 33:
        if(progress_changed) {
            text_progress_init("HUMPH!", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 4:
        if(progress_changed) {
            text_progress_init("WHAT DO YOU WANT?", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 7:
        if(progress_changed) {
            text_progress_init("ME? WANT?", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 10:
        if(progress_changed) {
            text_progress_init("LET'S TEST YOUR", "LUCK", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 13:
        if(progress_changed) {
            text_progress_init("ANSWER THIS", "QUESTION AND ...", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 18:
        if(progress_changed) {
            text_progress_init("YOU'LL BE FREE!", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 23:
        if(progress_changed) {
            text_progress_init("NOW LETS SEE...", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 1:
        menu_render(&menu_1);
        break;
    case 2:
        if(progress_changed) {
            text_progress_init("FOR A SMALL FEE...", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 5:
        if(progress_changed) {
            text_progress_init("I'LL LET YOU GO", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 8:
        if(progress_changed) {
            text_progress_init("SOUND FAIR?", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 15:
        if(progress_changed) {
            text_progress_init("NO! DEFINITELY NOT", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 20:
        if(progress_changed) {
            text_progress_init("HAVE IT YOUR WAY", "THEN!", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 25:
        if(progress_changed) {
            text_progress_init("I'LL TAKE IT ALL!", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 31:
        if(progress_changed) {
            text_progress_init("HAHAHA!", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 16:
        if(progress_changed) {
            text_progress_init("FINE...", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 21:
        if(progress_changed) {
            text_progress_init("VERY WELL THEN", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 26:
        if(progress_changed) {
            text_progress_init("JUST ONE SHOULD BE", "ENOUGH", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 32:
        if(progress_changed) {
            text_progress_init("SEE YOU AROUND", "", &frame);
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
            text_progress_init("HOW MANY STEPS", "HAVE YOU TAKEN?", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 19:
        if(progress_changed) {
            text_progress_init("EVEN OR ODD?", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 29:
        if(progress_changed) {
            text_progress_init("EVEN", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 35:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 38:
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
            text_progress_init("ODD", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 36:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 39:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 24:
        menu_render(&menu_24);
        break;
    case 28:
        if(progress_changed) {
            text_progress_init("WOW CORRECT!", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 34:
        if(progress_changed) {
            text_progress_init("LET ME REWARD YOU", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 37:
        if(progress_changed) {
            text_progress_init("SOMETHING SPECIAL,", "TOO!", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 40:
        if(progress_changed) {
            text_progress_init("", "", &frame);
            character_start_talking(CHARACTER_MODEL_NONE);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_NONE);
        };
        break;
    case 41:
        if(progress_changed) {
            text_progress_init("SEEMS LIKE ...", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 42:
        if(progress_changed) {
            text_progress_init("YOU NEED TO LEARN", "A LESSON", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 43:
        if(progress_changed) {
            text_progress_init("HERE IS A FEE FOR", "MY TIME", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 44:
        if(progress_changed) {
            text_progress_init("THAT WILL BE ALL", "", &frame);
            character_start_talking(CHARACTER_MODEL_BANDIT_A);
        }
        if(!text_draw_frame_progress(&frame))
        {
            character_stop_talking(CHARACTER_MODEL_BANDIT_A);
        };
        break;
    case 45:
        if(progress_changed) {
            text_progress_init("...", "", &frame);
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

BANKREF(gen_scene_bandit_ref)
struct Scene gen_scene_bandit =
{
    .process_input = process_input,
    .render = render,
};
