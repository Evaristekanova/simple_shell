#ifndef SHELL_H
#define SHELL_H

/* definition of macros */
#define bufsize 1024


/* standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* function prototypes */
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_paths(void);
char *concat(const char *str1, const char *str2);









#endif /* SHELL_H */
