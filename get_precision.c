#include "main.h"
#include <stdarg.h>
#include <stdbool.h>

/**
 * get_precision - Get the precision value from the format string
 * @format: The format string
 *
 * Return: The precision value or -1 if precision is not specified
 */
int get_precision(const char *format)
{
    int precision = -1; // Default value if precision is not specified
    bool precision_found = false;

    while (*format)
    {
        if (*format == '.')
        {
            format++; // Move past the '.' character
            precision = 0; // Initialize precision value

            // Parse digits to determine precision value
            while (*format >= '0' && *format <= '9')
            {
                precision = precision * 10 + (*format - '0');
                format++;
            }

            precision_found = true;
        }
        else
        {
            format++; // Move to the next character
        }
    }

    return (precision_found ? precision : -1);
}
