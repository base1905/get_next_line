
#include "get_next_line.h"

static int ft_n_check(char **lastbuf, char **line, char *n_pointer)
{
	char *temp;

	*n_pointer++ = '\0';
	*line = ft_strdup(*lastbuf);
	temp = ft_strdup(n_pointer);
	free(*lastbuf);
	*lastbuf = temp;
	return (1);
}


static int ft_process_output(char **lastbuf, char **line)
{
	char *n_pointer;

	if (*lastbuf && (n_pointer = ft_strchr(*lastbuf)))
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

	if (fd < 0 || fd > 13999 || line == NULL || BUFFER_SIZE <= 0
		|| (read(fd, buf, 0) < 0))
		return (-1);
	
	while ((reading = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[reading] = '\0';
		lastbuf[fd] = ft_strjoin_free(lastbuf[fd], buf);
		if ((n_pointer = ft_strchr(lastbuf[fd])))
			return (ft_n_check(&lastbuf[fd], line, n_pointer));
	}
	return (ft_process_output(&lastbuf[fd], line));
} 

// int main(void)
// {
// 	char 	*line;
// 	int		fd;
// 	int 	i;

// 	fd = open("nik2.txt", O_RDONLY);
// 	while ((i = get_next_line(fd, &line)))
// 	{
// 		printf("--%d-- %s\n", i, line);
// 		free(line);
// 	}
// 	printf("--%d-- %s\n", i, line);
// 	free(line);
// }