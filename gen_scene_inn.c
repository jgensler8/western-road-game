
#include "gen_scene_inn.h"

static void process_input(void) {

}

static void render(uint8_t swapped) {
    if(swapped){}
}

struct Scene gen_scene_inn =
{
    .process_input = process_input,
    .render = render,
};
