#include "hsh.h"
/**
 * sigint_handler - CTRL C free space from
 * STDIN
 * @signo: Signal Number
 */
void sigint_handler(int signo)
{
	/*Handle SIGINT (Ctrl+C) by freeing allocated memory*/
	(void) signo;
	free(tobi1.cmd);
	tobi1.exitcode = 0;
	exit(0);  /*Terminate the program gracefull*/
}

