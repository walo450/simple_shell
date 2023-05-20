#ifndef _GROUP_H
#define _GROUP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>



int prompt(int argc, char  *argv[], char **env);
int main(int argc, char *argv[], char **env);
char **filechk(char *str);
void forkexe(char **arstr, char *envp[]);
char **chstrtok(char *str);

#endif