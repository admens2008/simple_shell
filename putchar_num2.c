#include "hsh.h"
/**
 * putchar_number2 -  Recursive approach in
 * printing numbers
 * @n: The Number to print
 */
void putchar_number2(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}
	if ((num / 10) > 0)
		putchar_number(num / 10);

	_putchar2((num % 10) + '0');
}
