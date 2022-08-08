#ifndef SHELL_H
#define SHELL_H

/* standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* environment variables */
extern char **environ;

/* function prototypes */
int _shell(void);
void print_env(void);
int _getlineprocess(char **buffer, size_t *line_size, int *count);
char **_tokenparser(char *token, char *buffer);
unsigned int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int built_ins(char *buffer, char *token);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_paths(void);
char *concat(const char *str1, const char *str2);
int _noninteractive(int ac, char *av[]);
int _interpiped(char *av);
void _printnumber(int n);
void exec_child(char **cmds, char *av, int count);
char *_inPath(char **token);
void free_all(char *buffer, char **commands, char *heap_token);


#endif /* SHELL_H */
