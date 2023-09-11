#ifndef TERMANSI_H
#define TERMANSI_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

void        ansi_clearscreen();
const char *ansi_clearscreen_str();

void        ansi_cursor_setposition(int row, int col);
void        ansi_cursor_setposition_str(int row, int col, char *buf, size_t buflen);
void        ansi_cursor_move(int row, int col);
void        ansi_cursor_move_str(int row, int col, char *buf, size_t buflen);

void        ansi_style_reset();
const char *ansi_style_reset_str();
void        ansi_style_bold();
const char *ansi_style_bold_str();
void        ansi_style_bold_stop();
const char *ansi_style_bold_str_stop();
void        ansi_style_dim();
const char *ansi_style_dim_str();
void        ansi_style_dim_stop();
const char *ansi_style_dim_str_stop();
void        ansi_style_italic();
const char *ansi_style_italic_str();
void        ansi_style_italic_stop();
const char *ansi_style_italic_str_stop();
void        ansi_style_underline();
const char *ansi_style_underline_str();
void        ansi_style_underline_stop();
const char *ansi_style_underline_str_stop();
void        ansi_style_blinking();
const char *ansi_style_blinking_str();
void        ansi_style_blinking_stop();
const char *ansi_style_blinking_str_stop();
void        ansi_style_inverse();
const char *ansi_style_inverse_str();
void        ansi_style_inverse_stop();
const char *ansi_style_inverse_str_stop();
void        ansi_style_hidden();
const char *ansi_style_hidden_str();
void        ansi_style_hidden_stop();
const char *ansi_style_hidden_str_stop();
void        ansi_style_strikethrough();
const char *ansi_style_strikethrough_str();
void        ansi_style_strikethrough_stop();
const char *ansi_style_strikethrough_str_stop();

void        ansi_color_foreground256(int id);
void        ansi_color_foreground256_str(int id, char *buf, size_t buflen);
void        ansi_color_background256(int id);
void        ansi_color_background256_str(int id, char *buf, size_t buflen);
void        ansi_color_resetforeground();
const char *ansi_color_resetforeground_str();
void        ansi_color_resetbackground();
const char *ansi_color_resetbackground_str();
void        ansi_color_setforeground(int r, int g, int b);
void        ansi_color_setforeground_str(int r, int g, int b, char *buf, size_t buflen);
void        ansi_color_setbackground(int r, int g, int b);
void        ansi_color_setbackground_str(int r, int g, int b, char *buf, size_t buflen);

#ifdef TERMANSI_IMPLEMENTATION

void ansi_print(const char *string) {
    printf("%s", string);
    fflush(stdout);
}

void ansi_clearscreen() {
    ansi_print(ansi_clearscreen_str());
}

const char *ansi_clearscreen_str() {
    return "\033[2J";
}

void ansi_cursor_setposition(int row, int col) {
    char buf[13];
    ansi_cursor_setposition_str(row, col, buf, 13);
    ansi_print(buf);
}

void ansi_cursor_setposition_str(int row, int col, char *buf, size_t buflen) {
    assert(buflen > 12);
    assert(row > 0 && row < 1000);
    assert(col > 0 && col < 1000);

    memset(buf, 0, buflen);
    sprintf(buf, "\033[%d;%dH", row, col);
}

void ansi_cursor_move(int row, int col) {
    char buf[8];

    ansi_cursor_move_str(row, col, buf, 8);

    ansi_print(buf);
}

void ansi_cursor_move_str(int row, int col, char *buf, size_t buflen) {
    assert(buflen > 7);

    memset(buf, 0, buflen);

    if (row > 0) {
        sprintf(buf, "\033[%dB", row);
    } else if (row < 0) {
        sprintf(buf, "\033[%dA", -row);
    }

    if (col > 0) {
        sprintf(buf, "\033[%dC", col);
    } else if (col < 0) {
        sprintf(buf, "\033[%dD", -col);
    }
}

void ansi_style_reset() {
    ansi_print(ansi_style_reset_str());
}

const char *ansi_style_reset_str() {
    return "\033[0m";
}

void ansi_style_bold() {
    ansi_print(ansi_style_bold_str());
}

const char *ansi_style_bold_str() {
    return "\033[1m";
}

void ansi_style_bold_stop() {
    ansi_print(ansi_style_bold_str());
}

const char *ansi_style_bold_str_stop() {
    return "\033[22m";
}

void ansi_style_dim() {
    return ansi_print(ansi_style_dim_str());
}

const char *ansi_style_dim_str() {
    return "\033[2m";
}

void ansi_style_dim_stop() {
    return ansi_print(ansi_style_dim_str());
}

const char *ansi_style_dim_str_stop() {
    return "\033[22m";
}

void ansi_style_italic() {
    ansi_print(ansi_style_italic_str());
}

const char *ansi_style_italic_str() {
    return "\033[3m";
}

void ansi_style_italic_stop() {
    ansi_print(ansi_style_italic_str_stop());
}

const char *ansi_style_italic_str_stop() {
    return "\033[23m";
}

void ansi_style_underline() {
    ansi_print(ansi_style_underline_str());
}

const char *ansi_style_underline_str() {
    return "\033[4m";
}

void ansi_style_underline_stop() {
    ansi_print(ansi_style_underline_str_stop());
}

const char *ansi_style_underline_str_stop() {
    return "\033[24m";
}

void ansi_style_blinking() {
    ansi_print(ansi_style_blinking_str());
}

const char *ansi_style_blinking_str() {
    return "\033[5m";
}

void ansi_style_blinking_stop() {
    ansi_print(ansi_style_blinking_str_stop());
}

const char *ansi_style_blinking_str_stop() {
    return "\033[25m";
}

void ansi_style_inverse() {
    ansi_print(ansi_style_inverse_str());
}

const char *ansi_style_inverse_str() {
    return "\033[7m";
}

void ansi_style_inverse_stop() {
    ansi_print(ansi_style_inverse_str_stop());
}

const char *ansi_style_inverse_str_stop() {
    return "\033[27m";
}

void ansi_style_hidden() {
    ansi_print(ansi_style_hidden_str());
}

const char *ansi_style_hidden_str() {
    return "\033[8m";
}

void ansi_style_hidden_stop() {
    ansi_print(ansi_style_hidden_str_stop());
}

const char *ansi_style_hidden_str_stop() {
    return "\033[28m";
}

void ansi_style_strikethrough() {
    ansi_print(ansi_style_strikethrough_str());
}

const char *ansi_style_strikethrough_str() {
    return "\033[9m";
}

void ansi_style_strikethrough_stop() {
    ansi_print(ansi_style_strikethrough_str_stop());
}

const char *ansi_style_strikethrough_str_stop() {
    return "\033[29m";
}

void ansi_color_foreground256(int id) {
    char buf[14];
    ansi_color_foreground256_str(id, buf, 14);
    ansi_print(buf);
}

void ansi_color_foreground256_str(int id, char *buf, size_t buflen) {
    assert(0 <= id && id <= 255);
    assert(buflen > 13);

    memset(buf, 0, buflen);

    sprintf(buf, "\033[38;5;%dm", id);
}

void ansi_color_background256(int id) {
    char buf[14];
    ansi_color_background256_str(id, buf, 14);
    ansi_print(buf);
}

void ansi_color_background256_str(int id, char *buf, size_t buflen) {
    assert(0 <= id && id <= 255);
    assert(buflen > 13);

    memset(buf, 0, buflen);

    sprintf(buf, "\033[48;5;%dm", id);
}

void ansi_color_resetforeground() {
    ansi_print(ansi_color_resetforeground_str());
}

const char *ansi_color_resetforeground_str() {
    return "\033[38;5;39m";
}

void ansi_color_resetbackground() {
    ansi_print(ansi_color_resetbackground_str());
}

const char *ansi_color_resetbackground_str() {
    return "\033[48;5;39m";
}

void ansi_to_color_string(int r, int g, int b, char *buf, size_t buflen) {
    assert(buflen > 12);
    assert(0 <= r && r <= 255);
    assert(0 <= g && g <= 255);
    assert(0 <= b && b <= 255);

    memset(buf, 0, buflen);
    sprintf(buf, "%d;%d;%dm", r, g, b);
}

void ansi_color_setforeground(int r, int g, int b) {
    char buf[21];
    ansi_color_setforeground_str(r, g, b, buf, 21);
    ansi_print(buf);
}

void ansi_color_setforeground_str(int r, int g, int b, char *buf, size_t buflen) {
    char colorBuf[13];
    ansi_to_color_string(r, g, b, colorBuf, 13);

    memset(buf, 0, buflen);
    sprintf(buf, "\033[38;2;%s", colorBuf);
}

void ansi_color_setbackground(int r, int g, int b) {
    char buf[21];
    ansi_color_setbackground_str(r, g, b, buf, 21);
    ansi_print(buf);
}

void ansi_color_setbackground_str(int r, int g, int b, char *buf, size_t buflen) {
    char colorBuf[13];
    ansi_to_color_string(r, g, b, colorBuf, 13);

    memset(buf, 0, buflen);
    sprintf(buf, "\033[48;2;%s", colorBuf);
}

#endif // TERMANSI_IMPLEMENTATION

#endif // TERMANSI_H
