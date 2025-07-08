#pragma bank 2
#include "scene_road.h"
#include "gen/png2asset/bg_road.h"
#include "gen/png2asset/sp_cacti.h"
#include "gen/png2asset/sp_rock.h"
#include "gen/png2asset/sp_inn.h"
#include "gen/png2asset/sp_shack.h"

enum RoadSpriteIndexing
{
    // layout sprites in contiguous sprite indices; load once and move after
    ROAD_SPRITE_INDEXING_SEQUENTIAL,
    // layout sprites with overlapping sprite indivies; reload each frame
    ROAD_SPRITE_INDEXING_OVERLAP,
};

#define ROAD_SPRITE_MAX_FRAMES 4
struct RoadSprite
{
    uint8_t frame;
    struct SpriteAnimation frames[ROAD_SPRITE_MAX_FRAMES];
    const metasprite_t *metasprite;
    enum RoadSpriteIndexing indexing;
    uint8_t sp_start;
    uint8_t last_render;
};

#define SHEET_SLOT(slot) (16 * slot)

#define SP_CACTI_SHEET {                           \
    .tiles = sp_cacti_tiles,                       \
    .tiles_len = sp_cacti_TILE_COUNT,              \
    .sheet_start = SHEET_SLOT(0),                  \
    .sheet_frames = 1,                             \
    .sheet_frame_width_tiles = sp_cacti_WIDTH / 8, \
    .sheet_width_tiles = sp_cacti_WIDTH / 8,       \
    .palette_start = 0,                            \
    .palettes = sp_cacti_palettes,                 \
    .palettes_len = sp_cacti_PALETTE_COUNT,        \
}

struct RoadSprite rs_cacti = {
    .frames = {
        {
            .sheet = SP_CACTI_SHEET,
            .sheet_tile_x = 3,
            .sheet_tile_y = 1,
            .tile_width = 1,
            .tile_height = 1,
            .screen_x = 36,
            .screen_y = 22,
        },
        {
            .sheet = SP_CACTI_SHEET,
            .sheet_tile_x = 3,
            .sheet_tile_y = 2,
            .tile_width = 1,
            .tile_height = 2,
            .screen_x = 34,
            .screen_y = 28,
        },
        {
            .sheet = SP_CACTI_SHEET,
            .sheet_tile_x = 2,
            .sheet_tile_y = 1,
            .tile_width = 1,
            .tile_height = 3,
            .screen_x = 26,
            .screen_y = 44,
        },
        {
            .sheet = SP_CACTI_SHEET,
            .sheet_tile_x = 0,
            .sheet_tile_y = 0,
            .tile_width = 2,
            .tile_height = 4,
            .screen_x = 14,
            .screen_y = 60,
        },
    },
    // .indexing = ROAD_SPRITE_INDEXING_SEQUENTIAL,
    .indexing = ROAD_SPRITE_INDEXING_OVERLAP,
    .sp_start = 0,
};

#define SP_ROCK_SHEET {                           \
    .tiles = sp_rock_tiles,                       \
    .tiles_len = sp_rock_TILE_COUNT,              \
    .sheet_start = SHEET_SLOT(1),                 \
    .sheet_frames = 1,                            \
    .sheet_frame_width_tiles = sp_rock_WIDTH / 8, \
    .sheet_width_tiles = sp_rock_WIDTH / 8,       \
    .palette_start = 1,                           \
    .palettes = sp_rock_palettes,                 \
    .palettes_len = sp_rock_PALETTE_COUNT,        \
}

struct RoadSprite rs_rock = {
    .frames = {
        {
            .sheet = SP_ROCK_SHEET,
            .sheet_tile_x = 0,
            .sheet_tile_y = 0,
            .tile_width = 1,
            .tile_height = 1,
            .screen_x = 60,
            .screen_y = 5,
        },
        {
            .sheet = SP_ROCK_SHEET,
            .sheet_tile_x = 2,
            .sheet_tile_y = 0,
            .tile_width = 2,
            .tile_height = 2,
            .screen_x = 65,
            .screen_y = 10,
        },
        {
            .sheet = SP_ROCK_SHEET,
            .sheet_tile_x = 2,
            .sheet_tile_y = 2,
            .tile_width = 2,
            .tile_height = 2,
            .screen_x = 70,
            .screen_y = 20,
        },
        {
            .sheet = SP_ROCK_SHEET,
            .sheet_tile_x = 0,
            .sheet_tile_y = 2,
            .tile_width = 2,
            .tile_height = 2,
            .screen_x = 75,
            .screen_y = 30,
        },
    },
    .indexing = ROAD_SPRITE_INDEXING_OVERLAP,
    .sp_start = 8,
};

#define SP_EVENT_PALETTE_START 2
#define SP_EVENT_SHEET_TILES 16
#define SP_EVENT_SLOT SHEET_SLOT(3)

#define SP_INN_SHEET {                       \
    .tiles = sp_inn_tiles,                   \
    .tiles_len = sp_inn_TILE_COUNT,          \
    .sheet_start = SP_EVENT_SLOT,            \
    .sheet_frames = 1,                       \
    .sheet_frame_width_tiles = 4,            \
    .sheet_width_tiles = 4,                  \
    .palette_start = SP_EVENT_PALETTE_START, \
    .palettes = sp_inn_palettes,             \
    .palettes_len = sp_inn_PALETTE_COUNT,    \
}

#define SP_SHACK_SHEET {                           \
    .tiles = sp_shack_tiles,                       \
    .tiles_len = sp_shack_TILE_COUNT,              \
    .sheet_start = SP_EVENT_SLOT,                  \
    .sheet_frames = 1,                             \
    .sheet_frame_width_tiles = sp_shack_WIDTH / 8, \
    .sheet_width_tiles = sp_shack_WIDTH / 8,       \
    .palette_start = SP_EVENT_PALETTE_START,       \
    .palettes = sp_shack_palettes,                 \
    .palettes_len = sp_shack_PALETTE_COUNT,        \
}

#define ROAD_EVENT_SP_START 16
struct RoadSprite rs_events[ROAD_EVENT_COUNT] = {
    {0},
    // ROAD_EVENT_INN
    {
        .frames = {
            {
                .sheet = SP_INN_SHEET,
                .sheet_tile_x = 0,
                .sheet_tile_y = 0,
                .tile_width = 1,
                .tile_height = 1,
                .screen_x = 20,
                .screen_y = 5,
            },
            {
                .sheet = SP_INN_SHEET,
                .sheet_tile_x = 2,
                .sheet_tile_y = 0,
                .tile_width = 2,
                .tile_height = 2,
                .screen_x = 20,
                .screen_y = 5,
            },
            {
                .sheet = SP_INN_SHEET,
                .sheet_tile_x = 2,
                .sheet_tile_y = 2,
                .tile_width = 2,
                .tile_height = 2,
                .screen_x = 20,
                .screen_y = 5,
            },
            {
                .sheet = SP_INN_SHEET,
                .sheet_tile_x = 0,
                .sheet_tile_y = 2,
                .tile_width = 2,
                .tile_height = 2,
                .screen_x = 20,
                .screen_y = 5,
            },
        },
        .indexing = ROAD_SPRITE_INDEXING_OVERLAP,
        .sp_start = ROAD_EVENT_SP_START,
    },
    // ROAD_EVENT_CHERI_QUEST_1
    {
        .frames = {
            {
                .sheet = SP_SHACK_SHEET,
                .sheet_tile_x = 0,
                .sheet_tile_y = 0,
                .tile_width = 2,
                .tile_height = 2,
                .screen_x = 60,
                .screen_y = 5,
            },
        },
        .indexing = ROAD_SPRITE_INDEXING_OVERLAP,
        .sp_start = ROAD_EVENT_SP_START,
    },
};

struct RoadSprite *rs_left_item = &rs_cacti;
struct RoadSprite *rs_right_item = &rs_rock;
static inline void road_sprite_step(struct RoadSprite *rs)
{
    rs->frame++;
    if (rs->frame >= ROAD_SPRITE_MAX_FRAMES)
    {
        rs->frame = 0;
    }
}
static void process_input(void)
{
    if (joypad_a_pressed)
    {
        road_sprite_step(rs_left_item);
        road_sprite_step(rs_right_item);
        play_sfx_blip();
        state_on_step();
    }
    state_maybe_handle_event();
}

void render_road_sprite(struct RoadSprite *rs)
{
    if (rs->last_render != rs->frame)
    {
        uint8_t max_frames = rs->frames[3].sp_index_start + rs->frames[3].tile_height * rs->frames[3].tile_width;
        if (rs->indexing == ROAD_SPRITE_INDEXING_SEQUENTIAL)
        {
            animation_hide_range(rs->frames[0].sp_index_start, max_frames);
            animation_move_sprite(&rs->frames[rs->frame]);
        }
        else if (rs->indexing == ROAD_SPRITE_INDEXING_OVERLAP)
        {
            animation_hide_range(rs->frames[3].sp_index_start, max_frames);
            animation_init_sprite_animation(&rs->frames[rs->frame], rs->metasprite);
        }
        rs->last_render = rs->frame;
    }
}

void init_road_sprite(struct RoadSprite *rs)
{
    animation_init_sprite_sheet(&rs->frames[0].sheet);
    for (uint8_t frame = 0; frame < ROAD_SPRITE_MAX_FRAMES; frame++)
    {
        if (rs->indexing == ROAD_SPRITE_INDEXING_SEQUENTIAL)
        {
            if (frame == 0)
            {
                rs->frames[frame].sp_index_start = rs->sp_start;
            }
            else
            {
                rs->frames[frame].sp_index_start = rs->frames[frame - 1].sp_index_start + rs->frames[frame - 1].tile_height * rs->frames[frame - 1].tile_width;
            }
            animation_init_sprite_animation(&rs->frames[frame], rs->metasprite);
        }
        else if (rs->indexing == ROAD_SPRITE_INDEXING_OVERLAP)
        {
            rs->frames[frame].sp_index_start = rs->sp_start;
        }
    }
    // force render by setting an impossible last_render
    rs->last_render = ROAD_SPRITE_MAX_FRAMES + 1;
    rs->frame = 0;
}

static void render(struct SceneRenderOptions *options)
{
    if (options->swapped)
    {
        // palettes
        palette_util_init_bkg(PALETTE_UTIL_BG(bg_road));

        // sprites
        set_bkg_data(SCENE_BG_TILE_DATA_START, 64, bg_road_tiles);
        struct PaletteArgs pargs = {
            .metasprites = ANIMATE_DEFAULT_METASPRITE(bg_road),
            .palette_start = 1,
        };
        set_bkg_offset(4, 4, 8, 8, SCENE_BG_TILE_DATA_START, &pargs);
        text_draw_frame("A TO STEP", EMPTY);

        // unforunately, can't be initialized in struct declaration
        rs_cacti.metasprite = ANIMATE_DEFAULT_METASPRITE(sp_cacti);
        init_road_sprite(&rs_cacti);
        rs_rock.metasprite = ANIMATE_DEFAULT_METASPRITE(sp_rock);
        init_road_sprite(&rs_rock);
    }
    render_road_sprite(&rs_cacti);
    render_road_sprite(&rs_rock);
}

BANKREF(scene_road_ref)
struct Scene scene_road = {
    .process_input = process_input,
    .render = render,
};