#include <stddef.h>
#include <stdint.h>
#include "drivers/vga.h"
#define KERNEL_VERSION "0.1"

k_init(char* videomem)
{
    char message1[21] = "Hello, Kernel World!";
    char message2[24] = "Kernel Version v0.1"; // Kernel Version == KERNEL_VERSION
    char message3[19] = "Kernel Has Booted!";
    clear_screen(videomem);
    cursor_index = 0;

    cursor_index -= CHAR_PER_ROW; // Quick Fix for It displaying not Properly
    k_printf(videomem, message1);


    k_printf(videomem, message2);
    k_printf(videomem, message3);
    return 0;
}

kernelmain()
{
    char* videomem = k_initVideoMem();
    k_init(videomem);
    
}