#include "scene_shop.h"
#include "scene_road.h"

BANKREF_EXTERN(scene_road_ref)
static void process_input(void)
{
    queue_scene(&scene_road, BANK(scene_road_ref));
}

static void render(struct SceneRenderOptions *options)
{
}

BANKREF(scene_shop_ref)
struct Scene scene_shop = {
    .process_input = process_input,
    .render = render,
};