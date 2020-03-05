#pragma once
#include "../lib/std.h"
#define SPACE " "
#define NORMAL_COLOR 0x02
#define CHAR_PER_ROW 160

int cursor_index = 0;




char* k_initVideoMem()
{
    char* vidmem=(char*)0xb8000;
    return vidmem;
}
void k_putChar(char* videomem, char* text, int text_index, int index, int color)
{
    videomem[text_index] = text[index];
}

void k_printf(char* videomem, char* text)
{
    cursor_index += CHAR_PER_ROW;
    int i = 0;
    int j = 0;
    int num = strlen(text); // to be replaced with length or strlen(text);
    int len = num*2;
    j += cursor_index;
    while (i < len/2 || j < len/2)
    {
    k_putChar(videomem, text, j, i, NORMAL_COLOR);
    i++;
    j += 2;
    k_putChar(videomem, text, j, i, NORMAL_COLOR);
    }
    
    
}

void clear_screen(char* videomem)
{
    char s[2] = SPACE;
    int slen = CHAR_PER_ROW*25-1;
    int i = cursor_index;
    while (i < slen)
    {
        k_putChar(videomem, s, i, 0, NORMAL_COLOR);
        i += 2;
    }
    cursor_index = 0;
}