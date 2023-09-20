#include "main.h"

/**
 * get_width - Parses the format string to calculate the width.
 * @format: The formatted string containing conversion specifiers.
 * @i: A pointer to the current position in the format string.
 * @list: The va_list containing the variable arguments.
 *
 * Return: The calculated width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a digit */
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			/* Get the width from the variable arguments using va_arg */
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	/* Update the current position pointer based on the width parsing */
	*i = curr_i - 1;

	return (width);
}
