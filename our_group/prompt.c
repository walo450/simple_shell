#include "group.h"

/**
 * argc- counts the number of arguments
 * argv- the pointer of arguments.
 * env
 * 
 * Return: 1 success, -1 failure
*/

int prompt(char **argv[], char **env)
{
	char *buff = NULL;
        char *prompt = " @ ";
        int i, status;
        size_t buff_size = 0;
        ssize_t bytes;
        pid_t wpid;
        char *argv[] = {NULL, NULL};
//int wstatus;
// struct stat statbuf;

        while(1)
        {
               if (isatty(SDTIN_FILENO))
			   printf("@" );

               // write (STDOUT_FILENO, prompt, 2);

                bytes = getline(&buff, &buff_size, stdin);
               if (bytes == 1)
               {
                       perror ("Error > getline");
                       free(buff);
                       exit (Exit_FAILURE);
               }
			   i = 0;
			   while (buff[i])
			   {
				if (buff[bytes - 1 ]== '\n')
                    buff[bytes - 1 ] = '\0';
				 
			   }
                
				
				argv[0] = buff;
                wid = fork();
                if (wpid == -1)
                {
                        perror("Error (fork)");
                        exit (EXIT_FAILURE);
                }
                if (wpid == 0)
                       // execute (buff, *statbuf, env);

                //if (waitpid(wpid, *wsatus, 0) == -1)
                {
                       /** perror("Erro (wait)");
                        exit(EXIT_FAILURE);*/
						       
		if  (execve(argv[0], argv, env)== -1)
		printf("%s no such file", argv[0]);
		     }
		
		else
		   wait(&status);
		}


}

