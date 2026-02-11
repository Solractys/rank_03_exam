#include <stdio.h>
#include <stdlib.h>

int	count_numbers(char **str)
{
}

int *create_num_array(char **argv)
{
	int size = count_numbers(argv);
	int *num_array = malloc(sizeof(int) * size);
	while (argv[i] != NULL)
	{
		num_array[i] = atoi(argv[i]);
		i++;
	}
	return (num_array);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int n = atoi(av[1]);
	int *num_array = create_num_array(av + 1);
	return (0);
}
