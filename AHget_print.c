#include "main.h"

/**
 * AHget_print - Gets the appropriate printing function based on the format specifier.
 * @s: The format specifier character.
 *
 * Description:
 * This function examines the format specifier 's' and returns a pointer to
 * the appropriate printing function based on the specifier. If no matching
 * specifier is found, it returns NULL.
 *
 * Return: A pointer to the printing function, or NULL if not found.
 *
 * Authors: Ehoneah Obed & Abdulhakeem Badejo
 */
int (*AHget_print(char s))(va_list, flags_t *)
{
    /* Check the format specifier 's' and return the corresponding printing function */
    switch (s)
    {
        case 'c':
            return (AH_print_char);
       /* Return pointer to char printing function */
        case 's':
            return (AH_print_str); 
        /* Return pointer to string printing function */
        case 'd':
        case 'i':
            return (AH_print_int);
      /* Return pointer to int printing function */
        default:
            return (NULL); 
     /* Return NULL for unsupported specifiers */
    }
}
