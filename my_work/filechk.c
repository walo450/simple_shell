#include "group.h"

/// @brief 
/// @param str 
/// @return 
char **filechk(char *str)
{
	DIR *dir = opendir("/bin");
	char *temp, *cats;
	struct dirent *entity;

	if (dir == NULL)
	     return (NULL);
		entity = readdir(dir);
		while(entity != NULL)
		{
			temp_entity ->d_name;
			if(_strcmp(temp, str) == 0)
			{
				cats = _strcapt("/bin", str);
				closedir(dir);
				return(cats);
			}
			entity = readdir(dir);
		}
		closedir(dir);
		return (NULL);
}