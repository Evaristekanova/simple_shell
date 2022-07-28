# Simple Shell

### Description: 
> This is an implementation of a simple UNIX command interpreter that mimics the working of the shell. It rudimentarily resembles the first Unix shell by Thompson shell, introduced in the first version of Unix in 1971 which was a simple command interpreter, not designed for scripting. 

___

#### Requirements:
* simple_shell is compiled on Ubuntu 20.04 LTS by using:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

#### Usage:
The simple_shell works both in interactive mode and also in non-interactive mode:

* Interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
* Non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

___

### Authors:

> This project is a collaboration between:
* [Evariste Dusingizimana](https://github.com/Evaristekanova)
* [Joab O. Nyamagiri](https://github.com/jonyamagiri) 

