#define TERMANSI_IMPLEMENTATION
#include "termansi.h"

int main() {
    ansi_clearscreen();
    ansi_cursor_setposition(1, 1);

    // DOESNT WORK
    // ansi_cursor_move(5, 5);

    ansi_style_italic();
    ansi_style_bold();
    ansi_style_underline();
    ansi_style_inverse();
    ansi_style_strikethrough();
    printf(":)\n");
    ansi_style_reset();

    // DOESNT SEEM TO WORK
    // ansi_style_blinking();

/*
void        ansi_color_resetforeground();
void        ansi_color_resetbackground();
void        ansi_color_setforeground(int r, int g, int b);
void        ansi_color_setbackground(int r, int g, int b);
*/
}
