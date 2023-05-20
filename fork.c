#include "shell.h"

void forkexe(char **arstr, char *envp[])
{
	pid_t wpid;
	int status;

	wpid = fork();
	if (wpid < 0)
	{
		perror("Error (fork)");
		return;
	}
	if (wpid == 0)
	{
		if (execve(arstr[0], arstr, envp) == -1)
		    perror("./shell: No such file or directory\n")
    }
	else
	   wait(&status);

}