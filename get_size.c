#include "main.h"
#include <stdarg.h>

/**
 * get_size - Get the size of the data type based on length modifiers
 * @format: The format string
 *
 * Return: The size of the data type (1 for char, 2 for short, 4 for int, 8 for long)
 */
int get_size(const char *format)
{
    int size = 4; // Default size for int (without length modifiers)

    while (*format)
    {
        if (*format == 'l')
            size = 8; // 'l' indicates long, set size to 8 for long
        else if (*format == 'h')
            size = 2; // 'h' indicates short, set size to 2 for short
        format++;
    }

    return (size);
}
