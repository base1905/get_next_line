#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char	*line;
	int		fd;
	int		i;
	//int		fd4;
	//int		fd5;
	

	// reading from file
	printf("reading file \n");
	fd = open("nik2.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		printf("fd=%d gnl=%d %s\n", fd, i, line);
		free(line);
	}
	printf("fd=%d gnl=%d %s\n", fd, i, line);
	free(line);
	printf("\n");

	// fd4 = open("multiple1.txt", O_RDONLY);
	// i = get_next_line(fd4, &line);
	// printf("fd=%d gnl=%d %s\n", fd4, i, line);

	// fd5 = open("multiple2.txt", O_RDONLY);

	// i = get_next_line(fd5, &line);
	// printf("fd=%d gnl=%d %s\n", fd5, i, line);
	
	// i = get_next_line(fd4, &line);
	// printf("fd=%d gnl=%d %s\n", fd4, i, line);
	// printf("\n");
}