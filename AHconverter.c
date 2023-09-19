#include "main.h"

/**
 * AH_converter - Converts a number to a string representation in the given base.
 * @n: The input number to be converted.
 * @base: The base in which to represent the number (e.g., decimal, hexadecimal).
 * @lowercase: A flag indicating whether hexadecimal values should be lowercase.
 *
 * Return: A string representation of the number.
 *
 * Authors: Ehoneah Obed & Abdulhakeem Badejo
 */
char *AH_converter(unsigned long int n, int base, int lowercase)
{
    static char *AH_r;     
    /* Character set for digits in the specified base */
    static char AH_buffer[50]; 
    /* Buffer to store the resulting string */
    char *AH_p;        
    /* Pointer to the current position in the buffer */

    /* Define the character set based on the lowercase flag */
    AH_r = (lowercase)
        ? "0123456789abcdef"
        : "0123456789ABCDEF";
    AH_p = &AH_buffer[49];    
    /* Start from the end of the buffer and work backward */
    *AH_p = '\0';           
    /* Null-terminate the string */

    /* Convert the number to the specified base and store it in the buffer */
    do {
        *--AH_p = AH_r[n % base]; 
        /* Add the digit to the buffer */
        n /= base;        
        /* Move to the next digit */
    } while (n != 0);
    /* Return a pointer to the beginning of the resulting string */
    return (AH_p); 
}
