#include "hsh.h"
/**
 * _stdout - handles
 * standard output 1 and standard error 2
 * @str: string to print
 * @n: length of the string
 */
void _stdout(char *str, int n)
{
	write(n, str, strlen(str));

}
