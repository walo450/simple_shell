#include "group.h"

/**
 * input_buff - this buffers chained commands
 * @info: parameter struct
 * @buff: address of buffer
 * @s: address of size var
 *
 * Return: bytes read
 */
ssize_t input_buff(info_t *info, char **buff, size_t *s)
{
	ssize_t n = 0;
	size_t s_p = 0;

	if (!*s) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buff);*/
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		n = getline(buff, &s_p, stdin);
#else
		n = _getline(info, buff, &s_p);
#endif
		if (n > 0)
		{
			if ((*buff)[n - 1] == '\n')
			{
				(*buff)[n - 1] = '\0'; /* remove trailing newline */
				n--;
			}
			info->linecount_flag = 1;
			remove_comments(*buff);
			build_history_list(info, *buff, info->histcount++);
			/* if (_strchr(*buff, ';')) is this a command chain? */
			{
				*s = n;
				info->cmd_buff = buff;
			}
		}
	}
	return (n);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buff; /* the ';' command chain buffer */
	static size_t x, y, s;
	ssize_t n = 0;
	char **buff_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	n = input_buff(info, &buff, &s);
	if (n == -1) /* EOF */
		return (-1);
	if (s)	/* we have commands left in the chain buffer */
	{
		y = x; /* init new iterator to current buf position */
		p = buff + x; /* get pointer for return */

		check_chain(info, buff, &y, x, x);
		while (y < s) /* iterate to semicolon or end */
		{
			if (is_chain(info, buff, &y))
				break;
			y++;
		}

		i = y + 1; /* increment past nulled ';'' */
		if (x >= s) /* reached end of buffer? */
		{
			x = s = 0; /* reset position and length */
			info->cmd_buff_type = CMD_NORM;
		}

		*buff_p = p; /* pass back pointer to current command position */
		return (_strs(p)); /* return length of current command */
	}

	*buff_p = buff; /* else not a chain, pass back buffer from _getline() */
	return (n); /* return length of buffer from _getline() */
}

/**
 * read_buff - reads a buffer
 * @info: parameter struct
 * @buff: buffer
 * @x: size
 *
 * Return: n
 */
ssize_t read_buff(info_t *info, char *buff, size_t *x)
{
	ssize_t n = 0;

	if (*x)
		return (0);
	n = read(info->readfd, buff, READ_BUF_SIZE);
	if (n >= 0)
		*x = n;
	return (n);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: t
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buff[READ_BUF_SIZE];
	static size_t x, s;
	size_t l;
	ssize_t n = 0, t = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		t = *length;
	if (x == s)
		x = s = 0;

	n = read_buff(info, buff, &s);
	if (n == -1 || (n == 0 && s == 0))
		return (-1);

	c = _strchr(buff + x, '\n');
	l = c ? 1 + (unsigned int)(c - buff) : s;
	new_p = _realloc(p, t, t ? t + l : l + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (t)
		_strncat(new_p, buff + x, l - x);
	else
		_strncpy(new_p, buff + x, l - x + 1);

	t += l - x;
	x = l;
	p = new_p;

	if (length)
		*length = t;
	*ptr = p;
	return (t);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}