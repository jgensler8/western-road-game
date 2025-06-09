
#include "gen_scene_intro.h"

static void process_input(void) {

}

static void render(uint8_t swapped) {
    if(swapped){}
}

struct Scene gen_scene_intro =
{
    .process_input = process_input,
    .render = render,
};
