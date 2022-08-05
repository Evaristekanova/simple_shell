 #include "shell.h"
 
 /**
* main - entry point of the program
* Desc: program that displays a prompt and waits for user to type a command
*/
 
 int main(void)
 {
 	char *buffer = NULL;
 	size_t n = 0;
 	
 	while (1)
 	{
 		printf("shell~$ ");
 		getline(&buffer, &n, stdin);
 		printf("You entered: %s\n", buffer);
 	} 	
 }
