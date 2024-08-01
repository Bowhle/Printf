#include "main.h"
#include <stdlib.h>

/**
 * print_bnr - Prints a decimal number as binary.
 * @arguments: The list of arguments.
 * @buf: The buffer pointer.
 * @ibuf: The index for the buffer pointer.
 * Return: The number of characters printed.
 */
int print_bnr(va_list arguments, char *buf, unsigned int ibuf)
{
    int int_input, count, i;
    char binary[33]; // 32 bits + null terminator

    int_input = va_arg(arguments, int);

    // Handle the case for 0 directly
    if (int_input == 0)
    {
        ibuf = handl_buf(buf, '0', ibuf);
        return (1);
    }

    // Fill the binary representation
    fill_binary_array(binary, int_input, 0, 32);

    // Print binary representation
    count = 0;
    int first_one = 0;
    for (i = 0; i < 32; i++)
    {
        if (binary[i] == '1')
            first_one = 1;

        if (first_one)
        {
            ibuf = handl_buf(buf, binary[i], ibuf);
            count++;
        }
    }

    return (count);
}
