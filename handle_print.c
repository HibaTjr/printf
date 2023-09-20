#include "main.h"

/**
 * handle_print - Handles the printing of arguments based on their type.
 * @fmt: The formatted string containing conversion specifiers.
 * @ind: A pointer to the current position in the format string.
 * @list: The va_list containing the variable arguments.
 * @buffer: Buffer array to handle the print.
 * @flags: Active flags for formatting.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: The number of characters printed (1 or 2) or -1 on failure.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;

	/* Array of format specifiers and their corresponding functions */
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	/* Loop through the format specifiers and call the corresponding function */
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}

	/* Handle the case when no matching format specifier is found */
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1); /* Invalid format string */

		unknown_len += write(1, "%%", 1); /* Print the '%' character */

		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1); /* Successfully handled width specifier */
		}

		unknown_len += write(1, &fmt[*ind], 1); /* Print the unknown character */
		return (unknown_len);
	}

	return (printed_chars);
}
