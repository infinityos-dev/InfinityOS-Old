#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
    bool shift_is_down;
    bool caps_locked;
} PS2KeyboardProps;

void PS2_PrintScancodeToAscii(uint8_t scancode);
