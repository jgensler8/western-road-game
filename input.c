#pragma bank 0
#include "input.h"
#include <gbdk/platform.h>

uint8_t input_last;
uint8_t joypad_a_pressed;
uint8_t joypad_b_pressed;
uint8_t joypad_start_pressed;
uint8_t joypad_select_pressed;
uint8_t joypad_up_pressed;
uint8_t joypad_down_pressed;
uint8_t joypad_left_pressed;
uint8_t joypad_right_pressed;
// stateful input using global variable
void input_scan(void)
{
    // exclusive or
    uint8_t input = joypad();
    if (!input)
    {
        input_last = 0;
    }
    if (input ^ input_last)
    {
        input_last = input;
        joypad_a_pressed = input & J_A;
        joypad_b_pressed = input & J_B;
        joypad_start_pressed = input & J_START;
        joypad_select_pressed = input & J_SELECT;
        joypad_up_pressed = input & J_UP;
        joypad_down_pressed = input & J_DOWN;
        joypad_left_pressed = input & J_LEFT;
        joypad_right_pressed = input & J_RIGHT;
    }
    else
    {
        joypad_a_pressed = 0;
        joypad_b_pressed = 0;
        joypad_start_pressed = 0;
        joypad_select_pressed = 0;
        joypad_up_pressed = 0;
        joypad_down_pressed = 0;
        joypad_left_pressed = 0;
        joypad_right_pressed = 0;
    }
}