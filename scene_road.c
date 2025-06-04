#include "scene_road.h"

static void process_input(void)
{
}
static void render(uint8_t swapped)
{
    text_draw_frame("ROAD", "TIME");
}
struct Scene scene_road = {
    .process_input = process_input,
    .render = render,
};