#include "main.h"

/**
 * print_buf - prints buffer
 * @buf: buffer pointer
 * @nbuf: the number of bytes to print
 * Return: the number of bytes printed
 */
int print_buf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}
