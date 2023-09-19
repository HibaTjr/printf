#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_binary - Print an integer in binary format
 * @args: The va_list containing the integer to print
 *
 * Return: The number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int num_bits = sizeof(n) * 8; // Number of bits in an unsigned int
    int num_chars = 0;
    int leading_zero = 0;

    for (int i = num_bits - 1; i >= 0; i--)
    {
        int bit = (n >> i) & 1; // Extract the i-th bit from the right

        if (bit || leading_zero || i == 0)
        {
            leading_zero = 1;
            num_chars += write(1, (bit ? "1" : "0"), 1);
        }
    }

    return (num_chars);
}
