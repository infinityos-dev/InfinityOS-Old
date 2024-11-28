void PS2_PrintScancodeToAscii(uint8_t scancode) {
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
            printf("Q");
            break;
        case 0x11:
            printf("W");
            break;
        case 0x12:
            printf("E");
            break;
        case 0x13:
            printf("R");
            break;
        case 0x14:
            printf("T");
            break;
        case 0x15:
            printf("Y");
            break;
        case 0x16:
            printf("U");
            break;
        case 0x17:
            printf("I");
            break;
        case 0x18:
            printf("O");
            break;
        case 0x19:
            printf("P");
            break;
        case 0x1A:
            printf("[");
            break;
        case 0x1B:
            printf("]");
            break;
        case 0x1C:
            printf("Enter");
            break;
        case 0x1D:
            printf("Left Ctrl");
            break;
        case 0x1E:
            printf("A");
            break;
        case 0x1F:
            printf("S");
            break;
        case 0x20:
            printf("D");
            break;
        case 0x21:
            printf("F");
            break;
        case 0x22:
            printf("G");
            break;
        case 0x23:
            printf("H");
            break;
        case 0x24:
            printf("J");
            break;
        case 0x25:
            printf("K");
            break;
        case 0x26:
            printf("L");
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
            printf("Left Shift");
            break;
        case 0x2B:
            printf("\\");
            break;
        case 0x2C:
            printf("Z");
            break;
        case 0x2D:
            printf("X");
            break;
        case 0x2E:
            printf("C");
            break;
        case 0x2F:
            printf("V");
            break;
        case 0x30:
            printf("B");
            break;
        case 0x31:
            printf("N");
            break;
        case 0x32:
            printf("M");
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
            printf("Right Shift");
            break;
        case 0x37:
            printf("Keypad *");
            break;
        case 0x38:
            printf("Left Alt");
            break;
        case 0x39:
            printf("Space");
            break;
        default:
            if (scancode <= 0x7F) {
                printf("Unknown key down");
            } else if (scancode <= 0x39 + 0x80) {
                printf("Key up ");
                printf("%d", scancode - 0x80);
            } else {
                printf("Unknown key up");
            }
            break;
    }
}
