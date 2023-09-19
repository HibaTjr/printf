#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Print a character
 * @args: The va_list containing the character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - Print a string
 * @args: The va_list containing the string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (str == NULL)
        str = "(null)";

    while (str[len])
    {
        write(1, &str[len], 1);
        len++;
    }

    return (len);
}

/**
 * print_percent - Print a percent character
 * @args: Unused variable arguments
 *
 * Return: Always 1 (the percent character)
 */
int print_percent(__attribute__((unused)) va_list args)
{
    return (write(1, "%", 1));
}

/**
 * print_integer - Print an integer
 * @args: The va_list containing the integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    int num_len = num_length(n);

    return (print_number(n, num_len));
}

/**
 * num_length - Calculate the number of digits in an integer
 * @n: The integer to count digits for
 *
 * Return: The number of digits in the integer
 */
int num_length(int n)
{
    int len = 0;

    if (n == 0)
        return (1);

    while (n != 0)
    {
        n /= 10;
        len++;
    }

    return (len);
}

/**
 * print_number - Print an integer with a specified number of digits
 * @n: The integer to print
 * @num_len: The number of digits to print
 *
 * Return: The number of characters printed
 */
int print_number(int n, int num_len)
{
    int num_chars = 0;

    if (n == 0)
    {
        return (write(1, "0", 1));
    }

    if (n < 0)
    {
        num_chars += write(1, "-", 1);
        n = -n;
    }

    if (num_len > 0)
    {
        char *num_str = malloc(num_len);
        if (num_str == NULL)
            return (-1);

        snprintf(num_str, num_len, "%d", n);
        num_chars += write(1, num_str, num_len);

        free(num_str);
    }

    return (num_chars);
}
