/* AHprint_int.c */
#include "main.h"

/**
 * AHprint_int - Prints an integer.
 * @lst: va_list of arguments from _AH_printf.
 * @flg: Pointer to the struct flags determining
 * if a flag is passed to _AH_printf.
 *
 * Return: The number of characters printed.
 */
int AHprint_int(va_list lst, flags_t *flg)
{
    int n = va_arg(lst, int);
    int res = AHcount_digit(n);

    if (flg->space == 1 && flg->plus == 0 && n >= 0)
        res += _putchar(' ');
/* Print a space if ' ' flag is set and n is non-negative */
    if (flg->plus == 1 && n >= 0)
        res += _putchar('+');
/* Print a plus sign if '+' flag is set and n is non-negative */
    if (n <= 0)
        res++;
/* Increase the result count if n is negative or zero */
    AHprint_number(n);
/* Print the integer */
    return (res);
/* Return the total number of characters printed */
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @lst: va_list of arguments from _AH_printf.
 * @flg: Pointer to the struct flags determining
 * if a flag is passed to _AH_printf.
 *
 * Return: The number of characters printed.
 */
int AHprint_unsigned(va_list lst, flags_t *flg)
{
    unsigned int u = va_arg(lst, unsigned int);
    char *s = convert(u, 10, 0);

    (void)flg;
/* Suppress unused variable warning */
    return (_puts(s));
/* Print the unsigned integer as a string */
}

/**
 * AHprint_number - Helper function that prints all the digits of an integer.
 * @n: The integer to be printed.
 */
void AHprint_number(int n)
{
    unsigned int n1;

    if (n < 0)
    {
        _putchar('-');
/* Print a minus sign for negative numbers */
        n1 = -n;
/* Take the absolute value of n */
    }
    else
        n1 = n;

    if (n1 / 10)
        AHprint_number(n1 / 10);
/* Recursively print digits */
    _putchar((n1 % 10) + '0');
/* Print the last digit as a character */
}

/**
 * AHcount_digit - Returns the number of digits in an integer.
 * @i: The integer to evaluate.
 *
 * Return: The number of digits.
 */
int AHcount_digit(int i)
{
    unsigned int d = 0;
    unsigned int u;

    if (i < 0)
        u = i * -1;
/* Calculate the absolute value of i for negative numbers */
    else
        u = i;

    while (u != 0)
    {
        u /= 10;
/* Divide by 10 to move to the next digit */
        d++;
/* Increment the digit count */
    }
    return (d);
 /* Return the number of digits */
}
