#include  "hsh.h"
/**
 * checkforletter - Checks if as letter
 * was entered with the eit command
 * @str: exit args
 * Return: 0 if success otherwise 2
 */
int checkforletter(char *str)
{

	int i  = 0;

	while (str[i])
	{
		if (str[i] < '0' ||  str[i] > '9')
		{
			return (2);
		}
		i++;
	}
	return (0);
}


