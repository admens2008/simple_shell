#include "hsh.h"
int main(int argc, char **argv);
void cleanup(void);
/**
 * cleanup - ======
 */
void cleanup(void)
{
if (tobi1.cmd != NULL)
	free(tobi1.cmd);
}
/**
 * main - main function alsokno as the entry pointof the program
 * @argc: argument count
 * @argv: list of string arguments
 * Return: int ( 1 or 0)
 */
int main(int argc, char **argv)
{
	char *arg[25000] = {NULL};
	int byte = 0;
	size_t size;
	int isecho = 1;
	char *token = NULL;
	int i = 0;

	isecho = isatty(STDIN_FILENO);
	tobi1.errnum = 0;
	tobi1.exitcode = 0;
	tobi1.app_name = argv[0];
	signal(SIGINT, sigint_handler);
	atexit(cleanup);
	if (argc >= 2)
	{
		handle_file(argv[1]);
		exit(0);
	}
	while (1)
	{
		byte = getline(&tobi1.cmd, &size, stdin);
		if (byte == -1)
		{
			break;
		}
		if (strchr(tobi1.cmd, ';') != NULL)
		{
			tobi1.errnum++;
			tobi1.colon = 1;
			tokenize_semicolon(tobi1.cmd);
			tobi1.colon = 0;
			if (isecho == 0)
				break;
			continue;
		}
		else if (strchr(tobi1.cmd, '&') != NULL || strchr(tobi1.cmd, '|') != NULL)
		{
			tobi1.errnum++;
			tobi1.colon = 1;
			tokenize_semicolon(tobi1.cmd);
			tobi1.colon = 0;
			if (isecho == 0)
				break;
			continue;
		}
		else
		{
			token = strtok(tobi1.cmd, " \"\'\n\t\r");
			while (token)
			{
				if (token[0] == '#')
				{
					arg[i] = NULL;
					break;
				}
				arg[i] = token;
				token = strtok(NULL, " \"\'\n\t\r");
				i++;
			}
			arg[i] = NULL;
			i = 0;
			if (arg[0] == NULL)
			{
				if (isecho == 0)
					break;
				continue;
			}
			if (strcmp(arg[0], "exit") == 0)
			{
				if (arg[1] == NULL)
				{
					break;
				}
				else
				{
					handle_exit(arg[1], tobi1.cmd);
				}
			}
			else if (strcmp(arg[0], "env") == 0)
			{
				while (environ[i])
				{
					_stdout(environ[i], 1);
					_stdout("\n", 1);
					i++;
				}
				i = 0;
				if (isecho == 0)
					break;
				continue;
			}
			else
			{
				if (arg[1] != NULL)
					execute(arg, arg[1]);
				else
					execute(arg, "none");
				if (isecho == 0)
					break;
				continue;
			}

		}
	}
	free(tobi1.cmd);
	return (0);

}
