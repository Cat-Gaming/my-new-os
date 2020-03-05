#pragma once
#include <stddef.h>
#include <stdint.h>

size_t strlen(const char *str)
{
    size_t length = 0;
    while (*str++)
        length++;
    
    return (length);
}