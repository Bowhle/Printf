#include "main.h"

/**
 * handl_buf - Adds a character to the buffer
 * @buf: the buffer pointer
 * @c: the character to concatenate
 * @ibuf: index of buffer pointer
 * Return: The updated index in the buffer.
 */
unsigned int handl_buf(char *buf, char c, unsigned int ibuf)
{
	buf[ibuf] = c;
	return (ibuf + 1);
}
