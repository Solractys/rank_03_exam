// ler tudo do fd e guardar em algum lugar
// fazer a busca/subst 
// printar tudo guardado

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif 

char	*read_line(void)
{
	char	b[BUFFER_SIZE + 1] = "";
	char	*tmp = calloc(1, sizeof(char));
	int	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(0, b, BUFFER_SIZE);
		b[bytes_read] = 0;
		tmp = realloc(tmp, bytes_read + strlen(tmp) + 1);
		memmove(tmp + strlen(tmp), b, bytes_read + 1);
		tmp[bytes_read + strlen(tmp)] = 0;
	}
	return (tmp);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return (1);
	char *buffer = read_line();
  char *limiter = av[1];
  int limiter_len = strlen(limiter);
  int i = 0;
  int j = 0;
  while (buffer[i] != '\0')
  {
    j = 0;
    while (buffer[i + j] == limiter[j])
      j++;
    if (j == limiter_len)
    {
      int x = j;
      while (x--)
      {
        write (1, "*", 1);
      }
      i = j + i;
      continue ;
    }
    write (1, &buffer[i], 1);
    i++;
  }
	return (0);
}

