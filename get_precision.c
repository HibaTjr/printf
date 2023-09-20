#include "main.h"

/**
 * get_precision - Parses the format string to calculate the precision for printing.
 * @format: The formatted string containing conversion specifiers.
 * @i: A pointer to the current position in the format string.
 * @list: The list of arguments to be printed.
 * Return: The calculated precision value.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* Check if the format specifies precision with a period '.' */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* Iterate through the format string to extract the precision value */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a digit */
		if (is_digit(format[curr_i]))
		{
			/* Update the precision based on the digit */
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		/* Check if the current character is '*' to indicate a variable precision */
		else if (format[curr_i] == '*')
		{
			/* Skip the '*' character */
			curr_i++;
			/* Retrieve the precision value from the argument list */
			precision = va_arg(list, int);
			break;
		}
		/* If a non-digit character is encountered, exit the loop */
		else
			break;
	}

	/* Update the current position pointer */
	*i = curr_i - 1;

	return (precision);
}
