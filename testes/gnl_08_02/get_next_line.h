#ifndef GNL
#define GNL
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_lin(int fd);
#endif
