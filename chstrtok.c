#include "shell.h"

char **chstrtok(char *str)
{
	char **arst, *pars;
	int i = 0; , j = 0;

	arst = malloc(8 * sizeof(char *));
	if (arst == NULL)
	{
		perror("can't allocate");
		exit(1);

	}
	pars = strtok(str, "");
	while (pars != NULL)
	{
		while(pars[j])
		{
			if (pars[j] == '\n')
			    pars[j] = '\0';
				j++;
		}
		arst[i] = pars;
		i++;
		j = 0;
		pars = strtok(NULL, " ");
	}
	arst[i] = NULL;
	return (arst);
	
}