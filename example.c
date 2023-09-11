#define TERMANSI_IMPLEMENTATION
#include "termansi.h"

int main() {
    ansi_clearscreen();
    ansi_cursor_setposition(1, 1);

    ansi_style_italic();
    printf("Italic hello!\n");
    ansi_style_italic_stop();

    ansi_style_bold();
    ansi_style_strikethrough();
    printf("Bold strikethrough hi!\n");
    ansi_style_bold_stop();
    ansi_style_strikethrough_stop();

    printf("\n");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            int id = i * 16 + j;
            ansi_color_foreground256(id);
            printf("%6d", id);
        }
        printf("\n");
    }
    ansi_color_resetforeground();

    ansi_style_reset();
}
