/* AHprint_alpha.c */
#include "main.h"

/**
 * AHprint_string - Prints a string by looping through it and printing each character.
 * @lst: va_list arguments from _printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _printf.
 * Return: The number of characters printed.
 */
int AHprint_string(va_list lst, flags_t *flg)
{
    char *str = va_arg(lst, char *);

    (void)flg; // Unused flag parameter

    if (!str)
        str = "(null)";
    return (AH_puts(str)); // Use AH_puts to print the string
}

/**
 * AHprint_char - Prints a character.
 * @lst: va_list arguments from _printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _printf.
 * Return: The number of characters printed (always 1 for a single character).
 */
int AHprint_char(va_list lst, flags_t *flg)
{
    (void)flg;
   /* Unused flag parameter */
    AH_putchar(va_arg(lst, int));
   /* Use AH_putchar to print the character */
    return (1); 
    /* Return 1 for the number of characters printed */
}
