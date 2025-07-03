#include "scene_shop.h"
static void process_input(void)
{
}

static void render(struct SceneRenderOptions *options)
{
}

BANKREF(scene_shop_ref)
struct Scene scene_shop = {
    .process_input = process_input,
    .render = render,
};