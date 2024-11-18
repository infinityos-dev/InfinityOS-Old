#include "stdio.h"
#include "x86.h"

void putc(char c){
    x86_Video_WriteCharTeletype(c,0);
}
void puts(const char* str){
    while(*str){
        putc(*str);
        str++;
    }
}
#define PRINTF_STATE_NORMAL 0
void _cdecl printf(const char* fmt, ...){
    int* argp = (int*)&fmt;
    int state = PRINTF_STATE_NORMAL;
    argp++;
    while (*fmt)
    {
        switch (state)
        {
        case PRINTF_STATE_NORMAL:
            switch (*fmt)
            {
                case;
            }
        }
        fmt++;
    }
    
}