#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


char *read_line_ft(void)
{
	char b[BUFFER_SIZE + 1] = "";
	char *tmp = calloc(1, sizeof(char));
	int	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(0, b, BUFFER_SIZE);
		b[bytes_read] = 0;
		tmp = realloc(tmp, strlen(tmp) + bytes_read + 1);
		memmove(tmp + strlen(tmp), b, bytes_read + 1);
	}
	return (tmp);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
	{
		perror("Error: ");
		return (1);
	}
	char *word = av[1];
	int	word_len = strlen(word);
	char *buffer = read_line_ft();
	int i = 0;
	int j = 0;
	while (buffer[i] != '\0')
	{
		j = 0;
		while (buffer[i + j] == word[j])
			j++;
		if (j == word_len)
		{
			int x = j;
			while (x-- > 0)
				write (1, "*", 1);
			i += j;
			continue ;
		}
		write (1, &buffer[i], 1);
		i++;
	}
	return (0);
}

