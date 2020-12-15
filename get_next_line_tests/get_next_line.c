
#include "get_next_line.h"

static int ft_n_check(char **lastbuf, char **line, char *n_pointer)
{
	char *temp;

	*n_pointer = '\0';
	n_pointer++;
	temp = ft_strdup(n_pointer);
	
	*line = ft_strdup(*lastbuf);
	free(*lastbuf);
	*lastbuf = temp;
	return (1);
}


static int ft_result(char **lastbuf, char **line, ssize_t reading)
{
	char *n_pointer;

	if (reading == -1)
		return (-1);
	if (*lastbuf && (n_pointer = ft_strchr_n(*lastbuf)))
		return (ft_n_check(lastbuf, line, n_pointer));
	if (*lastbuf)
	{
		*line = *lastbuf;
 		*lastbuf = NULL;  
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char *lastbuf[ULIMITN];
	char buf[BUFFER_SIZE + 1];
	ssize_t reading;
	char *n_pointer;

	if (fd < 0 || fd > 13999 || line == NULL || BUFFER_SIZE <= 0 ||
	read(fd, buf, 0) < 0 )
		return (-1);
	while ((reading = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[reading] = '\0';
		lastbuf[fd] = ft_strjoin_free(lastbuf[fd], buf);
		if ((n_pointer = ft_strchr_n(lastbuf[fd])))
			return (ft_n_check(&lastbuf[fd], line, n_pointer));
	}
	
	return (ft_result(&lastbuf[fd], line, reading));
} 

int main(void)
{
	char 	*line;
	int		fd;
	int 	i;

	int		fd2;
	int		fd3;

	//bad fd
	printf("\n");
	printf("Bad fd\n");
	i = get_next_line(-1, &line);
	printf("**%d** %s\n", i, line);
	printf("\n");

	// n symbol in file
	printf("\\n symbol in file \n");
	fd2 = open("ntest.txt", O_RDONLY);
	i = get_next_line(fd2, &line);
	printf("**%d** %s\n", i, line);
	printf("\n");

	// empty file
	printf("empty file \n");
	fd3 = open("empty.txt", O_RDONLY);
	i = get_next_line(fd3, &line);
	printf("**%d** %s\n", i, line);
	printf("\n");


	// reading from file
	printf("reading file \n");
	fd = open("nik2.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		printf("**%d** %s\n", i, line);
		free(line);
	}
	printf("**%d** %s\n", i, line);
	free(line);
	printf("\n");

	// printf("\n");
	// printf("Stdio\n");
	// while ((i = get_next_line(1, &line)) > 0)
	// 	printf("**%d** %s\n", i, line);
	// printf("\n");


}