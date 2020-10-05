/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstealy <tstealy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 09:49:29 by tstealy           #+#    #+#             */
/*   Updated: 2020/06/20 09:02:37 by tstealy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_if_finish(char **dash, char **line)
{
	if (ft_strchr(*dash, '\0'))
	{
		*line = ft_strdup(*dash);
		free(*dash);
		*dash = NULL;
		return (0);
	}
	return (0);
}

int		ft_bytebz(ssize_t *bytes, char **dash)
{
	if (*bytes < 0)
	{
		if (*dash != NULL)
		{
			free(*dash);
			*dash = NULL;
		}
		return (-1);
	}
	return (0);
}

int		ft_get_line(ssize_t bytes, char **dash, char **line)
{
	char	*tmp;
	char	*tmp2;

	if (!bytes && !*dash)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_bytebz(&bytes, &*dash))
		return (-1);
	if ((tmp = ft_strchr(*dash, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*dash);
		tmp2 = ft_strdup(tmp + 1);
		free(*dash);
		*dash = tmp2;
		return (1);
	}
	else if (ft_if_finish(&*dash, &*line))
		return (0);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*dash[OPEN_MAX];
	ssize_t		nbytes;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 ||
		(!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((nbytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[nbytes] = '\0';
		if (!dash[fd])
			dash[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(dash[fd], buff);
			free(dash[fd]);
			dash[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (ft_get_line(nbytes, &dash[fd], &*line));
}
