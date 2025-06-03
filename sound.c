#include <gb/hardware.h>
#include "hUGEDriver.h"

extern const hUGESong_t single_beep;

void sound_init(void)
{
    // LCDC_REG = 0xD1;
    BGP_REG = 0b11100100;
    NR52_REG = 0x80;
    NR51_REG = 0xFF;
    NR50_REG = 0x77;

    __critical
    {
        // hUGE_init(&single_beep);
        add_VBL(hUGE_dosound);
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