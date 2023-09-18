#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to an index in the format string
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
    // Define the flags and their corresponding characters
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    int flags = 0;
    int j, curr_i;

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        // Check if the current character is a flag character
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[curr_i] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j]; // Set the corresponding flag bit
                break;
            }
        }

        // If the character is not a flag, exit the loop
        if (FLAGS_CH[j] == '\0')
        {
            break;
        }
    }

    *i = curr_i - 1; // Update the index

    return flags;
}
