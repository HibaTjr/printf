/* AHprint_bigS.c */
#include "main.h"

/**
 * AHprint_bigS - Prints non-printable characters in a special format.
 * (0 < ASCII value < 32 or >= 127) are printed as \x followed by the
 * ASCII code value in hexadecimal (uppercase).
 * @lst: va_list arguments from _AH_printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _AH_printf.
 *
 * Description:
 * This function takes a string 's' from the va_list 'lst' and processes it character
 * by character. Non-printable characters are printed in a special format: \x followed
 * by the ASCII code value in hexadecimal (uppercase). Printable characters are printed
 * as-is. If the input string is NULL, it prints "(null)".
 *
 * Return: The number of characters printed.
 */
int AHprint_bigS(va_list lst, flags_t *flg)
{
    int i, c = 0; 
/* Counter for characters printed */
    char *res;
    char *s = va_arg(lst, char *); 
/* Input string */

    (void)flg;
 /* Suppress unused variable warning */

    if (!s)
        return (_puts("(null)")); 
/* Print "(null)" if the input string is NULL */

    for (i = 0; s[i]; i++)
    {
        if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
        {
            _puts("\\x"); 
/* Print \x for non-printable character */
            c += 2;
            res = convert(s[i], 16, 0); 
/* Convert the character to hexadecimal */
            if (!res[1])
                c += _putchar('0'); 
/* Add leading '0' if needed */
            c += _puts(res); 
/* Print the hexadecimal value */
        }
        else
            c += _putchar(s[i]); 
/* Print printable character */
    }

    return (c); 
/* Return the total number of characters printed */
}

/**
 * AHprint_rev - Prints a string in reverse.
 * @lst: va_list arguments from _AH_printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _AH_printf.
 *
 * Description:
 * This function takes a string 's' from the va_list 'lst' and prints it in reverse order.
 * If the input string is NULL, it prints "(null)".
 *
 * Return: The length of the printed string.
 */
int AHprint_rev(va_list lst, flags_t *flg)
{
    int i = 0, j, c = 0; 
/* Counters for characters and string length */
    char *s = va_arg(lst, char *); 
/* Input string */

    (void)flg; 
/* Suppress unused variable warning */

    if (!s)
        s = "(null)"; 
/* Replace NULL with "(null)" */

    while (s[i])
        i++; 
/* Calculate the length of the string */

    for (j = i - 1; j >= 0; j--)
        c += _putchar(s[j]); 
/* Print the characters in reverse order */

    return (c); 
/* Return the length of the printed string */
}

/**
 * AHprint_rot13 - Prints a string using ROT13 encoding.
 * @lst: va_list arguments from _AH_printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _AH_printf.
 *
 * Description:
 * This function takes a string 's' from the va_list 'lst' and prints it using ROT13 encoding.
 * It only applies ROT13 encoding to alphabetical characters while leaving non-alphabetical
 * characters unchanged. If the input string is NULL, it prints "(null)".
 *
 * Return: The length of the printed string.
 */
int AHprint_rot13(va_list lst, flags_t *flg)
{
    int i, j, c = 0; 
/* Counters for characters and string length */
    char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
    char *s = va_arg(lst, char *);
 /* Input string */

    (void)flg; 
/* Suppress unused variable warning */

    for (j = 0; s[j]; j++)
    {
        if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
            c += _putchar(s[j]); 
/* Print non-alphabetical characters as-is */
        else
        {
            for (i = 0; i <= 52; i++)
            {
                if (s[j] == rot13[i])
                    c += _putchar(ROT13[i]); 
/* Apply ROT13 encoding to alphabetical characters */
            }
        }
    }

    return (c); 
/* Return the length of the printed string */
}

/**
 * AHprint_percent - Prints a percent character.
 * @lst: va_list arguments from _AH_printf.
 * @flg: Pointer to the struct flags that determines if a flag is passed to _AH_printf.
 *
 * Return: Always returns 1 (the number of characters printed).
 */
int AHprint_percent(va_list lst, flags_t *flg)
{
    (void)lst; 
/* Suppress unused variable warning */
    (void)flg; 
/* Suppress unused variable warning */

    return (_putchar('%')); 
/* Print the percent character and return 1 */
}
