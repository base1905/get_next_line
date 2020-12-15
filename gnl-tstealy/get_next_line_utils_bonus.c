/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstealy <tstealy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:15:09 by tstealy           #+#    #+#             */
/*   Updated: 2020/06/18 12:16:22 by tstealy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = ft_strlen(s1);
	if (!(s2 = malloc(i + 1)))
		return (NULL);
	ft_memcpy(s2, s1, i);
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dash;
	size_t		c1;
	size_t		c2;
	size_t		i;

	i = 0;
	c2 = ft_strlen(s1);
	c1 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(dash = (char *)malloc(sizeof(char) *
		ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (c1 != c2)
	{
		dash[i] = s1[c1];
		++i && ++c1;
	}
	c2 = 0;
	c1 = ft_strlen(s2);
	while (c2 != c1)
		dash[i++] = s2[c2++];
	dash[i] = '\0';
	return (dash);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
