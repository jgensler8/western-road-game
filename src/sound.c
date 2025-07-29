#pragma bank 0
#include "sound.h"
#include <gb/hardware.h>
#include <string.h>
#include "3p/hUGEDriver.h"

extern const hUGESong_t none;
extern const hUGESong_t road;
extern const hUGESong_t trader;
extern const hUGESong_t bandit;

static unsigned char current_P0[192] = {0};
static unsigned char current_P1[192] = {0};
static unsigned char current_P2[192] = {0};
static unsigned char current_P3[192] = {0};

static unsigned char *current_order1[] = {current_P0};
static unsigned char *current_order2[] = {current_P1};
static unsigned char *current_order3[] = {current_P2};
static unsigned char *current_order4[] = {current_P3};

static hUGEDutyInstr_t current_duty_instruments[15];
static hUGEWaveInstr_t current_wave_instruments[15];
static hUGENoiseInstr_t current_noise_instruments[15];
static unsigned char current_waves[16*16];

hUGESong_t current_song = {
    .tempo = 0,
    .order_cnt = 0,
    .order1 = current_order1,
    .order2 = current_order2,
    .order3 = current_order3,
    .order4 = current_order4,
    .duty_instruments = current_duty_instruments,
    .wave_instruments = current_wave_instruments,
    .noise_instruments = current_noise_instruments,
    .routines = NULL,
    .waves = current_waves,
};

static void copy_song_p(const struct hUGESong_t *src)
{
    current_song.tempo = src->tempo;
    // order
    current_song.order_cnt = src->order_cnt;
    memcpy(&current_P0, src->order1[0], 192);
    memcpy(&current_P1, src->order2[0], 192);
    memcpy(&current_P2, src->order3[0], 192);
    memcpy(&current_P3, src->order4[0], 192);
    // instruments
    memcpy(&current_duty_instruments, src->duty_instruments, sizeof(current_duty_instruments));
    memcpy(&current_wave_instruments, src->wave_instruments, sizeof(current_wave_instruments));
    memcpy(&current_noise_instruments, src->noise_instruments, sizeof(current_noise_instruments));
    // waves
    memcpy(&current_waves, src->waves, sizeof(current_waves));
}
static void copy_song(struct hUGESong_t src)
{
    current_song.tempo = src.tempo;
    // order
    current_song.order_cnt = src.order_cnt;
    memcpy(&current_P0, src.order1[0], 192);
    memcpy(&current_P1, src.order2[0], 192);
    memcpy(&current_P2, src.order3[0], 192);
    memcpy(&current_P3, src.order4[0], 192);
    // instruments
    memcpy(&current_duty_instruments, src.duty_instruments, sizeof(current_duty_instruments));
    memcpy(&current_wave_instruments, src.wave_instruments, sizeof(current_wave_instruments));
    memcpy(&current_noise_instruments, src.noise_instruments, sizeof(current_noise_instruments));
    // waves
    memcpy(&current_waves, src.waves, sizeof(current_waves));
}

void sound_init(void)
{
    // LCDC_REG = 0xD1;
    BGP_REG = 0b11100100;
    NR52_REG = 0x80;
    NR51_REG = 0xFF;
    NR50_REG = 0x77;

    __critical
    {
        sound_play_song(SONG_NONE);
        add_VBL(hUGE_dosound);
    }
}

void sound_play_song(enum Song song)
{
    __critical
    {
        uint8_t last_bank = CURRENT_BANK;
        SWITCH_ROM(9);
        switch (song)
        {
        case SONG_NONE:
            // hUGE_init(&none);
            copy_song_p(&none);
            break;
        case SONG_ROAD:
            copy_song_p(&road);
            break;
        case SONG_TRADER:
            // hUGE_init(&trader);
            copy_song_p(&trader);
            break;
        case SONG_BANDIT:
            // hUGE_init(&bandit);
            copy_song_p(&bandit);
            break;
        default:
            break;
        }
        hUGE_init((hUGESong_t *)&current_song);
        hUGE_reset_wave();
        SWITCH_ROM(last_bank);
    }
}

void play_sfx_blip(void)
{
    // Stop the channel first to reset it
    NR41_REG = 0x00; // Length: max (63)
    NR42_REG = 0xF1; // Volume/Envelope: Initial volume 15 (F), decrease (1), step time 1 (001)
    NR43_REG = 0x3F; // Frequency: max (fast noise)
    NR44_REG = 0x80; // Control: Trigger (start sound)
}

void play_sfx_high(void)
{
    NR10_REG = 0x00; // No sweep (optional, could add for a 'ping')
    NR11_REG = 0x80; // Length (no use) | Duty (50% wave) - 0x80 means 50% duty
    NR12_REG = 0xF1; // Initial volume (F=max) | Envelope (decrease) | Step time (1)
    // Frequency: Higher pitch (e.g., C6)
    NR13_REG = 0x83; // Low byte of frequency for C6 (1760 Hz)
    NR14_REG = 0x86; // Trigger | Length Enable (0x80 to trigger, 0x06 for high byte)
}