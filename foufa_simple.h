#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

/* all strings listing */
int _stringcp(char *s1, char *s2);
int _stringlg(char *s);
int _stringmp(char *s1, char *s2, int n);
char *_stringdup(char *s);
char *_stringch(char *s, char c);

void usage(char *cp, char **cmd);
char *_pathfind(void);

/* function free */
void _supplies(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

/* environ variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* list plugins builtin */
int _checker(char **cmd, char *buf);
void _myuser(void);
void _handler2(int m);
char **_tokens(char *line);
char *_pathvalid(char **path, char *command);
char *_end(char *path, char *command);
int _handler(char **command, char *line);
void _exitcmd(char **command, char *line);

void _print(void);

#endif/* this symbol has been added by Imane and Fatima Zahra*/
