#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>
#define BUFFER_SIZE 1
#include <fcntl.h>

char *read_line(void)
{
	char b[BUFFER_SIZE + 1] = "";
	char *tmp = malloc(1);
	tmp[0] = 0;
	int bytes_read;
	int fd = open("teste.txt", O_RDONLY);
	while ((bytes_read = read(fd, b, BUFFER_SIZE)) != 0)
	{
		tmp = realloc(tmp, bytes_read + strlen(tmp));
		memmove(tmp + strlen(tmp), b, bytes_read + 1);
		b[bytes_read] = 0;
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
	char *buffer = read_line();
	char *limiter = av[1];
	int len_limiter = strlen(limiter);
	int i, j = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i + j] == limiter[j])
			j++;
		if (j == len_limiter)
		{
			int x = j;
			while(x > 0)
			{
				write (1, "*", 1);
				x--;
			}
			i += j;
			continue ;
		}
		write (1, &buffer[i], 1);
		i++;
	}
	return (0);
}
