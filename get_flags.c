#include "main.h"

/**
 * get_flags - Parses the format string to determine active formatting flags.
 * @format: The formatted string containing conversion specifiers.
 * @i: A pointer to the current position in the format string.
 * Return: Flags: a bitwise combination of flag constants.
 */
int get_flags(const char *format, int *i)
{
	/* Flags: - + 0 # ' ' */
	/* Corresponding bit positions:  1  2  4  8   16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	/* Iterate through the format string starting from the current position */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a valid flag character */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				/* Set the corresponding flag bit */
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		/* If the character is not a flag character, exit the loop */
		if (FLAGS_CH[j] == '\0')
			break;
	}

	/* Update the current position pointer */
	*i = curr_i - 1;

	return (flags);
}
