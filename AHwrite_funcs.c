/* write_funcs.c */
#include "main.h"
#include <unistd.h>

/**
 * AH_putchar - Writes the character c to stdout using a buffer.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 * Description: AH_putchar uses a local buffer of 1024 to call write
 * as little as possible, enhancing performance.
 */
int AH_putchar(char c)
{
    static char buf[1024];
    static int i;

    if (c == -1 || i >= 1024)
    {
        write(1, &buf, i);
/* Write the buffer contents to stdout */
        i = 0;
/* Reset the buffer index */
    }
    if (c != -1)
    {
        buf[i] = c;
 /* Store the character in the buffer */
        i++;
    }
    return (1);
/* Return 1 to indicate success */
}

/**
 * _puts - Prints a string to stdout.
 * @s: Pointer to the string to print.
 *
 * Return: The number of characters written.
 */
int _puts(char *s)
{
    register int i;

    for (i = 0; s[i] != '\0'; i++)
        AH_putchar(s[i]);
/* Call AH_putchar to print each character */
    return (i);
/* Return the number of characters written */
}
