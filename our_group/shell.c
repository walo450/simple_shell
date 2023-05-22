#include "group.h"

int main(int argc, char *argv[], char **env)
{
        char **buff;
	size_t n = 20; t = 0 ; pt = 4;
	ssize_t bytes;
	char *poit, *wl;

	
   while(1)
{
               if (isatty(SDTIN_FILENO))
			   printf("@" );

               // write (STDOUT_FILENO, prompt, 2);
			   poit= malloc(sizeof(char) * n);
                bytes = getline(&buff, &buff_size, stdin);
               if (bytes == 1)
               {
                       perror ("Error > getline");
                       free(poit);
                       exit (EXIT_FAILURE);
               }
			   if (*poit  != '/n')
			   {
				buff = chstrtok(poit);
				if ( strcmp("exit", buff[0]) == 0)
				    break;
				t = checkinbuilt(buff[0]);
				wl = filechk(buff[0]);
				if (t == 0 && wl != NULL)
				     string[0] = wl;
			  pt = pathchk(buff[0]);
			  if (pt == 1)
			       forkexe(buff, env);
			  if (wl == NULL && pt == 0 && t == 0)
			      printf("./shell: No such file or directory\n");
			   }
			   }
			   free (wl);
			   free (pt);
			   free (buff);
			   exit (0); 
}
