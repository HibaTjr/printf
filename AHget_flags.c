#include "main.h"

/**
 * AHget_flag - Turns on flags if _AH_printf finds a flag modifier in the format string.
 * @s: Character that holds the flag specifier.
 * @f: Pointer to the struct flags in which we turn the flags on.
 *
 * Description:
 * This function examines the character 's' and checks if it represents a flag
 * modifier used in the format string of _AH_printf. If a flag modifier is found,
 * it sets the corresponding flag in the 'flags_t' structure 'f'.
 *
 * Return: 1 if a flag has been turned on, 0 otherwise.
 *
 * Authors: Ehoneah Obed & Abdulhakeem Badejo
 */
int AHget_flag(char s, flags_t *f)
{
    int i = 0;

    /* Check if the character 's' represents a flag modifier */
    switch (s)
    {
        case '+':
            f->plus = 1;   /* Set the "plus" flag to 1 */
            i = 1;         /* Indicate that a flag has been turned on */
            break;
        case ' ':
            f->space = 1;  /* Set the "space" flag to 1 */
            i = 1;         /* Indicate that a flag has been turned on */
            break;
        case '#':
            f->hash = 1;   /* Set the "hash" flag to 1 */
            i = 1;         /* Indicate that a flag has been turned on */
            break;
    }

    return (i);
}
