#define TERMANSI_IMPLEMENTATION
#include "termansi.h"

int main() {
    ansi_clearscreen();
    ansi_cursor_setposition(1, 1);

    ansi_style_italic();
    ansi_style_bold();
    ansi_style_underline();
    ansi_style_inverse();
    ansi_style_strikethrough();
    printf("hello :)\n");
    ansi_style_reset();
}
