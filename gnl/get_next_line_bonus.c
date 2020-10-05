/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:23:02 by tcarlena          #+#    #+#             */
/*   Updated: 2020/06/08 19:26:27 by tcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_getline_all(t_content *content, char **first_str)
{
	if (!(*first_str = malloc(sizeof(char) * (content->len + 1))))
		return (-1);
	(*first_str)[content->len] = '\0';
	while (content->len)
	{
		content->len--;
		(*first_str)[content->len] = content->line[content->len];
	}
	free(content->line);
	if (!(content->line = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	return (1);
}

static int		ft_getline_first(t_content *content, char **first_str, int i)
{
	int		j;
	char	*tmp;
	int		len_last;

	j = -1;
	if (!(*first_str = malloc(sizeof(char) * (i + 1))))
		return (-1);
	while (++j < i)
		(*first_str)[j] = content->line[j];
	(*first_str)[j] = '\0';
	if (!(tmp = malloc(sizeof(char) * (content->len - j - 1))))
		return (-1);
	len_last = content->len;
	content->len = 0;
	while (++i < len_last)
		tmp[content->len++] = content->line[i];
	free(content->line);
	content->line = tmp;
	return (1);
}

static int		ft_getstr_first(t_content *content, char **first_str)
{
	unsigned int i;

	*first_str = NULL;
	i = 0;
	while (i < content->len && content->line[i] != '\n')
		i++;
	if (i == content->len && content->status != BUFFER_SIZE &&
			content->len != 0)
	{
		if (!(ft_getline_all(content, first_str)))
			return (-1);
		return (0);
	}
	else if (i < content->len)
	{
		if (!(ft_getline_first(content, first_str, i)))
			return (-1);
	}
	return (1);
}

static int		ft_getstr(t_content *content, char **line)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	char	*first_str;
	int		status;

	if ((status = ft_getstr_first(content, &first_str)) == -1)
		return (-1);
	while (!first_str && content->status != 0)
	{
		if ((content->status = read(content->fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		if (!(tmp = ft_strjoin_len(content->line, buf, content->len,
						BUFFER_SIZE)))
			return (-1);
		free(content->line);
		content->line = tmp;
		content->len += content->status;
		if ((status = ft_getstr_first(content, &first_str)) == -1)
			return (-1);
	}
	*line = first_str;
	if (!content->status)
		return (0);
	return (status);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*elem;
	int				status;

	if (fd < 0 || !line)
		return (-1);
	if (!(elem = ft_getelem_fd(lst, fd)))
		if (!(elem = ft_lstnew_fd(&lst, fd)))
			return (ft_lstclear(lst));
	if (!((status = ft_getstr(elem->content, line))))
		ft_lstdelone(elem, &lst);
	if (!*line)
	{
		if (!(*line = malloc(sizeof(char) * 1)))
			return (ft_lstclear(lst));
		**line = '\0';
	}
	return (status);
}
