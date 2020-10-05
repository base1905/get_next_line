#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strdup(char *str)
{
	char	*new;
	char	*dst;

	new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	dst = new;
	while (*str)
	{
		*new = *str;
		new++;
		str++;
	}
	*new = '\0';
	return (dst);
}


char		*ft_strjoin_free(char *s1, char *s2)
{
	char *buf;
	int len1;
	int len2;
	char *result;

	if (!s1 && !s2)
		return (NULL);
	if (!(s1))
			return (ft_strdup(s2));
	if (!(s2))
			return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(buf = (char *)malloc(sizeof(char) * (len1 + len2 + 1 ))))
		return (NULL);
	result = buf;
	while (*s1)
		*buf++ = *s1++;
	free (s1 - len1);
	while (*s2)
		*buf++ = *s2++;
	*buf = '\0';
	return (result);
}


char	*ft_strchr(const char *s)
{
	char	*str;

	str = (char *)s;
	while (*str != '\n')
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

 