#include "group.h"

void pathchk(char *str)
{
	char *cmp = "/bin", *prt, *j;
	int u = 0, y = 0;

	prt = malloc(sizeof(char) * 50);
	if (prt == NULL)
	    return (0);
	while (cmp[u] != str[u])
	{
		if (cmp[u] != str[i])
		{
			free(prt);
			return (0);
		}
		u++;
	}
	while (str[u] != '\0')
	{
		prt[p] = str[u];
		p++;
		u++;

	}
	prt[p] ='\0';
	y = filechk(prt);
	if (y != Null)
	{
		free(prt);
		return(1);
	}
	return (0);
	
	
}