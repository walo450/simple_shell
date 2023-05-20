#include "group.h"

/**
 * _myenv - prints the current environment
 * This file contains the environment variables that are used to run the application
 * . To make any changes to these variables
 * Return: Always 0
 */

/**
 * _getenv - gets the value of an environ variable
 * : Structure containing potential arguments. Used to maintain
 * env var name
 *
 * Return: the value
 */

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}


char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *b;

	while (node)
	{
		b = starts_with(node->str, name);
		if (b && *b)
			return (b);
		node = node->next;
	}
	return (NULL);
}


int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}


int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}