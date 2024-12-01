#include "keyboard.h"

PS2KeyboardProps g_PS2KeyboardProps;

void PS2_PrintScancodeToAscii(uint8_t scancode) {
    bool is_uppercase = g_PS2KeyboardProps.caps_locked ^ g_PS2KeyboardProps.shift_is_down;

    switch (scancode) {
        case 0x0:
            printf("ERROR");
            break;
        case 0x1:
            printf("ESC");
            break;
        case 0x2:
            printf("1");
            break;
        case 0x3:
            printf("2");
            break;
        case 0x4:
            printf("3");
            break;
        case 0x5:
            printf("4");
            break;
        case 0x6:
            printf("5");
            break;
        case 0x7:
            printf("6");
            break;
        case 0x8:
            printf("7");
            break;
        case 0x9:
            printf("8");
            break;
        case 0xA:
            printf("9");
            break;
        case 0xB:
            printf("0");
            break;
        case 0xC:
            printf("-");
            break;
        case 0xD:
            printf("=");
            break;
        case 0xE:
            printf("Backspace");
            break;
        case 0xF:
            printf("Tab");
            break;
        case 0x10:
            printf(is_uppercase ? "Q" : "q");
            break;
        case 0x11:
            printf(is_uppercase ? "W" : "w");
            break;
        case 0x12:
            printf(is_uppercase ? "E" : "e");
            break;
        case 0x13:
            printf(is_uppercase ? "R" : "r");
            break;
        case 0x14:
            printf(is_uppercase ? "T" : "t");
            break;
        case 0x15:
            printf(is_uppercase ? "Y" : "y");
            break;
        case 0x16:
            printf(is_uppercase ? "U" : "u");
            break;
        case 0x17:
            printf(is_uppercase ? "I" : "i");
            break;
        case 0x18:
            printf(is_uppercase ? "O" : "o");
            break;
        case 0x19:
            printf(is_uppercase ? "P" : "p");
            break;
        case 0x1A:
            printf("[");
            break;
        case 0x1B:
            printf("]");
            break;
        case 0x1C:
            printf("\n");
            break;
        case 0x1D:
            printf("Left Ctrl");
            break;
        case 0x1E:
            printf(is_uppercase ? "A" : "a");
            break;
        case 0x1F:
            printf(is_uppercase ? "S" : "s");
            break;
        case 0x20:
            printf(is_uppercase ? "D" : "d");
            break;
        case 0x21:
            printf(is_uppercase ? "F" : "f");
            break;
        case 0x22:
            printf(is_uppercase ? "G" : "g");
            break;
        case 0x23:
            printf(is_uppercase ? "H" : "h");
            break;
        case 0x24:
            printf(is_uppercase ? "J" : "j");
            break;
        case 0x25:
            printf(is_uppercase ? "K" : "k");
            break;
        case 0x26:
            printf(is_uppercase ? "L" : "l");
            break;
        case 0x27:
            printf(";");
            break;
        case 0x28:
            printf("'");
            break;
        case 0x29:
            printf("`");
            break;
        case 0x2A: 
            g_PS2KeyboardProps.shift_is_down = true;
            break;
        case 0x2B:
            printf("\\");
            break;
        case 0x2C:
            printf(is_uppercase ? "Z" : "z");
            break;
        case 0x2D:
            printf(is_uppercase ? "X" : "x");
            break;
        case 0x2E:
            printf(is_uppercase ? "C" : "c");
            break;
        case 0x2F:
            printf(is_uppercase ? "V" : "v");
            break;
        case 0x30:
            printf(is_uppercase ? "B" : "b");
            break;
        case 0x31:
            printf(is_uppercase ? "N" : "n");
            break;
        case 0x32:
            printf(is_uppercase ? "M" : "m");
            break;
        case 0x33:
            printf(",");
            break;
        case 0x34:
            printf(".");
            break;
        case 0x35:
            printf("/");
            break;
        case 0x36:
            g_PS2KeyboardProps.shift_is_down = true;
            break;
        case 0x37:
            printf("Keypad *");
            break;
        case 0x38:
            printf("Left Alt");
            break;
        case 0x39:
            printf(" ");
            break;
        case 0xAA: 
            g_PS2KeyboardProps.shift_is_down = false;
            break;
        case 0xBA:
            g_PS2KeyboardProps.shift_is_down = false;
            break;
        default:
            printf("");
            break;
    }
}

