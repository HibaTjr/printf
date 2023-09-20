#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			if (format[i] == '\0')
				return (-1);  /* Incomplete format specifier */
			printed_chars += handle_format_specifier(format[i], args, buffer, &buff_ind);
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * handle_format_specifier - Handle a format specifier
 * @specifier: The format specifier character
 * @args: The variable argument list
 * @buffer: The buffer for storing output
 * @buff_ind: The buffer index
 *
 * Return: The number of characters printed
 */
int handle_format_specifier(char specifier, va_list args, char buffer[], int *buff_ind)
{
	int printed = 0;

	switch (specifier)
	{
		case 'c':
			printed = handle_char(va_arg(args, int), buffer, buff_ind);
			break;
		case 's':
			printed = handle_string(va_arg(args, char *), buffer, buff_ind);
			break;
		case '%':
			printed = handle_percent(buffer, buff_ind);
			break;
		/* Add cases for other conversion specifiers */
		default:
			printed = handle_unknown(specifier, buffer, buff_ind);
			break;
	}

	return (printed);
}

/* Implement functions like handle_char, handle_string, etc. */

