#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	if (argc != 2 && argv[1] == NULL)
		return (0);
	
	char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	char *line = NULL;

/*
	int res = get_next_line(fd, &line);
	printf("res : %d\n", res);
	printf("main line : %s\n", line);
	
	res = get_next_line(fd, &line);
	printf("res : %d\n", res);
	printf("main line : %s\n", line);


	res = get_next_line(fd, &line);
	printf("res : %d\n", res);
	printf("main line : %s\n", line);
*/

	while(get_next_line(fd, &line))
	{	
		printf("main line : %s\n", line);
	}


	printf("while out line : %s\n", line);
	
	close(fd);
	free(line);
	return (0);
}
