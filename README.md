
# ROM Bank Planning

| Bank | contents |
| --- | --- |
| 0 | hUGETracker, core libraries (types, text, input, sound, animate, scene_dialog) |
| 1 | core assets: loaded once then never switched to (font, border) |
| 2 | common gameplay: scene + asset (title, select, road) |
| 3 | all other specific assets (scene, data, text) |
| 4 | shack, cheri |
| 5 | trader |
| 6 | road fork |
| 7 | veronica, house |
| 8 | bandit |
| 9 | songs: none, road, trader, bandit |