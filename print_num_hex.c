#include "main.h"

/**
 * prinnhex - prints number in hexadecimal starting with 0x
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for a buffer pointer
 * Return: number of chars printed
 */
int prinnhex(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, isnegative, count, first_digit, i;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;

	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}

	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'x', ibuf);

	binary = malloc(sizeof(char) * 33); /* 32 bits + 1 for null terminator */
	if (binary == NULL)
		return (0);

	hexadecimal = malloc(sizeof(char) * 9); /* 8 digits + 1 for null terminator */
	if (hexadecimal == NULL)
	{
		free(binary);
		return (0);
	}

	fill_binary_array(binary, int_input, isnegative, 32);
	fill_hex_array(binary, hexadecimal, 0, 8);

	for (first_digit = count = 0, i = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}

	free(binary);
	free(hexadecimal);
	return (count + 2); /* Include the '0x' prefix in the count */
}
