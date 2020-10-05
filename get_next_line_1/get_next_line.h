#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ULIMITN 14000

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *str);
char		*ft_strjoin_free(char *s1, char *s2);
char	*ft_strchr_n(const char *s);
int get_next_line(int fd, char **line);


#endif
