#include <stdio.h>
#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 && argv[1] == NULL)
		return (0);
	
	char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	int fd_user_output = open("./user_output", O_RDWR | O_CREAT | O_TRUNC, 0644);

	char *line = NULL;
	
	int result = 1;


	while(result > 0)
	{	
		result = get_next_line(fd, &line);
		if (result != -1)
		{
			ft_putstr_fd(line, fd_user_output);
			if (result)
				ft_putchar_fd('\n', fd_user_output);
		}
		free(line);
	}

	close(fd);
	close(fd_user_output);
	return (0);
}
