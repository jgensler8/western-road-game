#pragma bank 2
#include "scene_road.h"
#include "road_sprite.h"
#include "gen/png2asset/bg_road.h"
#include "gen/metasprite_fix/bg_road.h"

static struct RoadSprite *rs_event_item;
static inline void road_sprite_step(struct RoadSprite *rs)
{
    rs->frame++;
    if (rs->frame >= ROAD_SPRITE_MAX_FRAMES)
    {
        rs->frame = 0;
    }
}
static uint8_t should_reinit_left = 0;
static void process_input(void)
{
    SCENE_OPTIONS_PROCESS_INPUT_TAKEOVER;
    if (joypad_a_pressed)
    {
        state_on_step();
        if (default_state.next_event_steps > ROAD_SPRITE_MAX_FRAMES - 1)
        {
            road_sprite_step(&rs_cacti);
        }
        else
        {
            road_sprite_step(rs_event_item);
        }
        road_sprite_step(&rs_rock);
        play_sfx_blip();
    }
    state_maybe_handle_event();
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        sound_play_song(SONG_ROAD);
        // palettes
        palette_util_init_bkg(PALETTE_UTIL_BG(bg_road));

        // sprites
        set_bkg_data(SCENE_BG_TILE_DATA_START, 64, bg_road_tiles);
        struct PaletteArgs pargs = {
            .palette_map = bg_road_palette_map,
            .palette_start = 1,
        };
        set_bkg_offset(4, 4, 8, 8, SCENE_BG_TILE_DATA_START, &pargs);
        text_draw_frame("A TO STEP", EMPTY);

        // road sprites
        init_road_sprite(&rs_cacti);
        init_road_sprite(&rs_rock);
        rs_rock.frame = 2;
        // generate road event
        state_generate_next_event();
        // road event init
        rs_event_item = &rs_events[default_state.next_event];
        init_road_sprite(rs_event_item);
    }
    SCENE_OPTIONS_RENDER_TAKEOVER;
    if (default_state.next_event_steps > ROAD_SPRITE_MAX_FRAMES)
    {
        render_road_sprite(&rs_cacti);
    }
    else
    {
        hide_sprites_range(0, 8);
        render_road_sprite(rs_event_item);
    }
    render_road_sprite(&rs_rock);
}

BANKREF(scene_road_ref)
struct Scene scene_road = {
    .process_input = process_input,
    .render = render,
};