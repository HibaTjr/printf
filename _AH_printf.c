#include "main.h"

/**
 * _AH_printf - Produces output according to a custom format.
 * @_AH_format: Custom format string containing characters and specifiers.
 *
 * Description:
 * This function calls the select_print_function() function, which determines
 * the appropriate printing function to call based on the conversion specifiers
 * contained within the _AH_format string.
 *
 * Return:
 * Length of the formatted output string.
 *
 * Authors:
 * Ehoneah Obed & Abdulhakeem Badejo
 */
int _AH_printf(const char *_AH_format, ...)
{
    int (*_AH_pfunc)(va_list, flags_t *);
    const char *_AH_p;
    va_list _AH_arguments;
    flags_t _AH_flags = {0, 0, 0};

    register int _AH_count = 0;

    va_start(_AH_arguments, _AH_format);

    /* Check for invalid format or empty format */
    if (!_AH_format || (_AH_format[0] == '%' && !_AH_format[1]))
        return (-1);

    /* Check for format starting with '%' and a space */
    if (_AH_format[0] == '%' && _AH_format[1] == ' ' && !_AH_format[2])
        return (-1);

    for (_AH_p = _AH_format; *_AH_p; _AH_p++)
    {
        if (*_AH_p == '%')
        {
            _AH_p++;
            if (*_AH_p == '%')
            {
                /* Handle double '%' as a literal character */
                _AH_count += _putchar('%');
                continue;
            }

            /* Process any flags associated with the conversion specifier */
            while (get_flag(*_AH_p, &_AH_flags))
                _AH_p++;

            /* Get the appropriate printing function based on the specifier */
            _AH_pfunc = get_print(*_AH_p);

            /* Call the printing function and update the count */
            _AH_count += (_AH_pfunc)
                ? _AH_pfunc(_AH_arguments, &_AH_flags)
                : _AH_printf("%%%c", *_AH_p); // Handle unsupported specifier
        }
        else
        {
            /* Handle non-'%' characters as literals */
            _AH_count += _putchar(*_AH_p);
        }
    }

    /* Indicate the end of the formatted output */
    _putchar(-1);

    /* Clean up and return the total character count */
    va_end(_AH_arguments);
    return (_AH_count);
}
