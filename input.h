#pragma once
#include <stdint.h>

extern uint8_t input_last;
extern uint8_t joypad_a_pressed;
extern uint8_t joypad_b_pressed;
extern uint8_t joypad_start_pressed;
extern uint8_t joypad_select_pressed;
extern uint8_t joypad_up_pressed;
extern uint8_t joypad_down_pressed;
extern uint8_t joypad_left_pressed;
extern uint8_t joypad_right_pressed;

void input_scan(void);