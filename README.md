# 0x15. C Shell

![The gates of shell](https://raw.githubusercontent.com/Cu7ious/simple_shell/medium/assets/shell.jpeg)

### Description
This is a school project which goal is to mirror the `sh` command-line interpreter (shell), written by Ken Thompson
in a limited scope.

### Synopsis
This version of the shell has a collection of custom built-in commands along
with the functionality of running scripts in the the various paths on a given operating system.

### Requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on `Ubuntu 14.04 LTS`
* Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
* All your files should end with a new line
* A `README.md file`, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl)
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to ([why?](//www.quora.com/Why-are-system-calls-expensive-in-operating-systems))

### List of allowed functions and system calls
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* fork (man 2 fork)
* free (man 3 free)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
* _exit (man 2 _exit)
* isatty (man 3 isatty)
* fflush (man 3 fflush)

### Environment
* [VirtualBox v.5.2.8](https://www.virtualbox.org/)
* [Ubuntu v.14.04 LTS](https://atlas.hashicorp.com/ubuntu/boxes/trusty64)
* [Vagrant v2.0.1](https://www.vagrantup.com/)

## Repo Contents

|   **File**    |  **Decription**                       |
|---------------|---------------------------------------|
|  `shell.h`	|  Header file: contains prototypes	|
|  `shell.c`	|  Main file: contains main function and an interactive mode loop|

### How to Use

1. Clone repo
```
git clone https://github.com/MitaliSengupta/simple_shell.git
```
2. Change directory to simple_shell
```
cd simple_shell/
```
3. Compile all the `.c` files in /simple_shell
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

### Interactive and Non-Interactive Mode

In interactive mode input is accepted from the keyboard.

```
$ ./hsh

$ ls -l
total 104
drwxr-xr-x 1 vagrant vagrant   800 Mar 28  2018 .
drwxr-xr-x 1 vagrant vagrant   352 Mar 27 15:22 ..
-rw-r--r-- 1 vagrant vagrant   164 Mar 28 15:32 AUTHORS
drwxr-xr-x 1 vagrant vagrant   352 Mar 20 21:12 exercises
-rw-r--r-- 1 vagrant vagrant   293 Mar 28 15:32 exit_handler.c
-rw-r--r-- 1 vagrant vagrant   250 Mar 28 15:32 find_chars_number.c
-rw-r--r-- 1 vagrant vagrant   968 Mar 28 15:32 find_str_seq.c
-rw-r--r-- 1 vagrant vagrant   494 Mar 28 15:32 get_str_seq.c
drwxr-xr-x 1 vagrant vagrant   480 Mar 28  2018 .git
-rw-r--r-- 1 vagrant vagrant   107 Mar 21 18:10 .gitignore
-rwxr-xr-x 1 vagrant vagrant 24304 Mar 28 15:44 hsh
-rw-r--r-- 1 vagrant vagrant   384 Mar 28 15:32 insertion_sort.c
-rw-r--r-- 1 vagrant vagrant  1042 Mar 28 16:14 man_1_simple_shell
-rw-r--r-- 1 vagrant vagrant  1277 Mar 28 15:43 path_resolver.c
-rw-r--r-- 1 vagrant vagrant   193 Mar 28 15:32 print_env.c
-rw-r--r-- 1 vagrant vagrant   246 Mar 21 18:10 _putchar.c
-rw-r--r-- 1 vagrant vagrant  4080 Mar 28  2018 README.md
-rw-r--r-- 1 vagrant vagrant   965 Mar 28 15:45 shell.c
-rw-r--r-- 1 vagrant vagrant  1080 Mar 28 15:32 shell.h
-rw-r--r-- 1 vagrant vagrant   141 Mar 28 15:32 sig_handler.c
-rw-r--r-- 1 vagrant vagrant   320 Mar 28 15:32 _strcat.c
-rw-r--r-- 1 vagrant vagrant   504 Mar 28 15:32 _strcmp.c
-rw-r--r-- 1 vagrant vagrant   392 Mar 27 14:59 _strcpy.c
-rw-r--r-- 1 vagrant vagrant   205 Mar 27 14:59 _strlen.c
-rw-r--r-- 1 vagrant vagrant  1047 Mar 28 15:43 _strtok.c

$ echo hello world
hello world

$
```

In non-interactive mode, the shell is run from commands being piped in. The subshell
is only opened as the command is carried out and closes at the completion of the command.

```
$ ls -l | ./hsh
total 104
drwxr-xr-x 1 vagrant vagrant   800 Mar 28  2018 .
drwxr-xr-x 1 vagrant vagrant   352 Mar 27 15:22 ..
-rw-r--r-- 1 vagrant vagrant   164 Mar 28 15:32 AUTHORS
drwxr-xr-x 1 vagrant vagrant   352 Mar 20 21:12 exercises
-rw-r--r-- 1 vagrant vagrant   293 Mar 28 15:32 exit_handler.c
-rw-r--r-- 1 vagrant vagrant   250 Mar 28 15:32 find_chars_number.c
-rw-r--r-- 1 vagrant vagrant   968 Mar 28 15:32 find_str_seq.c
-rw-r--r-- 1 vagrant vagrant   494 Mar 28 15:32 get_str_seq.c
drwxr-xr-x 1 vagrant vagrant   480 Mar 28  2018 .git
-rw-r--r-- 1 vagrant vagrant   107 Mar 21 18:10 .gitignore
-rwxr-xr-x 1 vagrant vagrant 24304 Mar 28 15:44 hsh
-rw-r--r-- 1 vagrant vagrant   384 Mar 28 15:32 insertion_sort.c
-rw-r--r-- 1 vagrant vagrant  1042 Mar 28 16:14 man_1_simple_shell
-rw-r--r-- 1 vagrant vagrant  1277 Mar 28 15:43 path_resolver.c
-rw-r--r-- 1 vagrant vagrant   193 Mar 28 15:32 print_env.c
-rw-r--r-- 1 vagrant vagrant   246 Mar 21 18:10 _putchar.c
-rw-r--r-- 1 vagrant vagrant  4080 Mar 28  2018 README.md
-rw-r--r-- 1 vagrant vagrant   965 Mar 28 15:45 shell.c
-rw-r--r-- 1 vagrant vagrant  1080 Mar 28 15:32 shell.h
-rw-r--r-- 1 vagrant vagrant   141 Mar 28 15:32 sig_handler.c
-rw-r--r-- 1 vagrant vagrant   320 Mar 28 15:32 _strcat.c
-rw-r--r-- 1 vagrant vagrant   504 Mar 28 15:32 _strcmp.c
-rw-r--r-- 1 vagrant vagrant   392 Mar 27 14:59 _strcpy.c
-rw-r--r-- 1 vagrant vagrant   205 Mar 27 14:59 _strlen.c
-rw-r--r-- 1 vagrant vagrant  1047 Mar 28 15:43 _strtok.c

$
```
### Builtins and commands
Below are some of the builtin commands used, for further information please refer to the man page - accessed in terminal with:
```
man ./man_1_simple_shell
```
#### Builtins:
* `env` (prints environmental variables)
* `exit` (exit program)
* `pwd` (prints current working directory)
> * `setenv` (sets a new environmental variable)
> * `unsetenv` (unsets an environmental variable)

### Function & SysCalls
`execve`, `exit`, `fork`, `free`, `getline`, `malloc`, `perror`, `wait`

## Notes
This shell does not handle aliases, comments, or history.


### Author

* Sergii Garkusha [Twitter](https://twitter.com/Cu7ious) | [Email](garkusha.sergiy@gmail.com)
* Artur Adamian | [GitHub](https://github.com/arturadamian) | [Twitter](https://twitter.com/arturadamian) | [LinkedIn](https://www.linkedin.com/in/arturadamian/)

Hi, I am Artur. I am a Software Engineer student at Holberton School where I currently study Web Development and polish my knowleges in low-level and object-oriented programming, as well as developing strong professional communication skills.
