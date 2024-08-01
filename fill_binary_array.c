#include "main.h"

/**
 * fill_binary_array - Fills a binary array with the binary representation.
 * @binary: The binary array to fill.
 * @n: The number to convert.
 * @start: Starting index in the array.
 * @size: Size of the binary array.
 * Return: The filled binary array.
 */
char *fill_binary_array(char *binary, unsigned int n, unsigned int start, unsigned int size)
{
	unsigned int I;

	// Initialize the binary array with '0'
	for (i = 0; i < size; i++)
	binary[i] = '0';
	binary[size] = '\0'; // Null-terminate the string

	// Convert number to binary
	for (i = 0; i < size; i++)
	{
	if (n & (1 << (size - i - 1)))
	binary[i] = '1';
	}
	return binary;
}
