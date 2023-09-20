#include "main.h"

/**
 * get_size - Parses the format string to calculate the size specifier.
 * @format: The formatted string containing conversion specifiers.
 * @i: A pointer to the current position in the format string.
 *
 * Return: The calculated size specifier.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	/* Check if the current character specifies a size modifier */
	if (format[curr_i] == 'l')
		size = S_LONG; /* Set size to long */
	else if (format[curr_i] == 'h')
		size = S_SHORT; /* Set size to short */

	/* Update the current position pointer based on whether a size modifier was found */
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
