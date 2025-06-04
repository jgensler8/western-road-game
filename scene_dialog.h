#include "scene_common.h"
void scene_dialog_init(char **new_dialogs, uint8_t new_dialog_count, struct Scene* new_next_scene);
void scene_dialog_process_input(void);
void scene_dialog_render(uint8_t swapped);