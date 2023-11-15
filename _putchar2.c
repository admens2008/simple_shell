#include "hsh.h"
/**
 * _putchar2 - modiied it to write to the stderr
 * @c: char to write to the descriptor
 * Return: return 1 on success
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar2(char c)
{
	return (write(1, &c, 1));
}
