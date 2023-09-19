#include "main.h"

/**
 * AHprint_string - Prints a string character by character.
 * @lst: va_list arguments from _AH_printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _AH_printf.
 *
 * Description:
 * This function is used to print a string character by character. It takes the input
 * string 's' from the va_list 'lst' and prints each character to the standard output.
 * If the input string is NULL, it prints "(null)".
 *
 * Return: The number of characters printed.
 */
int AHprint_string(va_list lst, flags_t *flg)
{
    char *s = va_arg(lst, char *);
    /* Input string */

    (void)flg;
    /* Suppress unused variable warning */

    /* Check if the input string is NULL and replace it with "(null)" */
    if (!s)
        s = "(null)";

    return (_puts(s));
    /* Print the string and return the number of characters printed */
}

/**
 * print_char - Prints a single character.
 * @lst: va_list arguments from _printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _printf.
 *
 * Description:
 * This function is used to print a single character. It takes the input character 'c'
 * from the va_list 'lst' and prints it to the standard output.
 *
 * Return: 1 (the number of characters printed, which is always 1 for a single character).
 */
int AHprint_string(va_list lst, flags_t *flg)
int print_char(va_list lst, flags_t *flg)
{
    (void)flg;
    /* Suppress unused variable warning */
    _putchar(va_arg(lst, int));
    /* Print the character */
    return (1);
    /* Return 1 (number of characters printed) */
}
