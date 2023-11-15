#ifndef HSH_H
#define HSH_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <error.h>
#include <fcntl.h>
#include <signal.h>
extern char **environ;
#define ARG_LENGTH 15000
/**
 * struct tobi - ==============
 * @tbi2: =======
 * @tobi_: ==========
 */
typedef struct tobi
{
	char *tbi2;
	void (*tobi_)(char *, const char *);
} tobi;

/**
 * struct data_t - application data
 * @cmd: command for the stdinput
 * @app_name: application name
 * @errnum: error number
 * @colon: colon entered
 * @isfile: is file or not file
 * @exitcode: exit code
 */
typedef struct data_t
{
	char *cmd;
	char *app_name;
	int errnum;
	int colon;
	int isfile;
	int exitcode;
} data_t;
data_t tobi1;
/*data_t tobi2;*/

void sigint_handler(int signo);
void _stdout(char *str, int n);
void putchar_number(int n);
void putchar_number2(int n);
void execute(char **args, char *ech);
int _putchar(char c);
int _putchar2(char c);
void freedoublepointer(char **args);
void finalexecution(char **args, char *command);
void tokenize_semicolon(char *command);
void handle_exit(char *args, char *command);
int checkforletter(char *str);
void freesinglepointer(char **args);
void handle_file(char *filename);

#endif
