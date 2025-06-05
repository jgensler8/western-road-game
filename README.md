
# ROM Bank Planning

| Bank | contents |
| --- | --- |
| 0 | hUGETracker, core libraries (types, text, input, sound, animate, scene_dialog) |
| 1 | core assets: loaded once then never switched to (font, border) |
| 2 | common gameplay: scene + asset (title, select, road) |
| 3-N | all other specific assets (scene, data, text) |
| 3 | scene_inn |