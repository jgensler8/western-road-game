#pragma once
enum Song {
    SONG_NONE,
    SONG_ROAD,
    SONG_TRADER,
    SONG_BANDIT,
    SONG_COUNT,
};

void sound_init(void);
void sound_play_song(enum Song song);
void play_sfx_blip(void);
void play_sfx_high(void);