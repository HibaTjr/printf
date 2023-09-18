#include "main.h"
#include <stdarg.h> // Include the necessary standard library for variable arguments

#define BUFF_SIZE 1024 // Define the buffer size

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);

            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);

            i++; // Move past the '%'

            int flags = get_flags(format, &i);
            int width = get_width(format, &i, args);
            int precision = get_precision(format, &i, args);
            int size = get_size(format, &i);

            int printed = handle_print(format, &i, args, buffer, flags, width, precision, size);

            if (printed == -1)
            {
                va_end(args);
                return -1;
            }

            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(args);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, &buffer[0], *buff_ind);
        *buff_ind = 0;
    }
}
