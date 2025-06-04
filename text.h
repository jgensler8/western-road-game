#include <stdint.h>

void text_init(void);

// frames

void clear_bkg(void);
void clear_bkg_frame(void);

#define EMPTY "\0"

void text_draw_frame(char *line_1, char *line_2);

#define PROGRESS_FRAME_WAIT 4
struct ProgressableFrame
{
    char *line_1;
    uint8_t line_1_len;
    char *line_2;
    uint8_t line_2_len;
    uint8_t l1_progress;
    uint8_t l2_progress;
    uint8_t skip;
    uint8_t wait;
};
void text_progress_init(char *line_1, char *line_2, struct ProgressableFrame *frame);
uint8_t text_draw_frame_progress(struct ProgressableFrame *frame);

// menu

#define MENU_MAX_OPTIONS 8
struct Menu
{
    uint8_t selection;
    uint8_t max_option;
    char *options[MENU_MAX_OPTIONS];
};
void menu_reset_state(void);
uint8_t menu_process_input(struct Menu *menu);
void menu_render(struct Menu *menu);