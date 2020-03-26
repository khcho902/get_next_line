#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	if (argc != 2 && argv[1] == NULL)
		return (0);
	
	char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	char *line;


	get_next_line(fd, &line);

	printf("%s\n", line);
/*
	for(int i = 0; i < BUFFER_SIZE; i++)
	{
		write(1, &line[i], 1);
	}
*/	
	close(fd);

	return (0);
}
