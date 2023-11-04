#include "hsh.h"
/**
 * putchar_number -  Recursive approach in
 * printing numbers
 * @n: The Number to print
 */
void putchar_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}
	if ((num / 10) > 0)
		putchar_number(num / 10);

	_putchar((num % 10) + '0');
}
