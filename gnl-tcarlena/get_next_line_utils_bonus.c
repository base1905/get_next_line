/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:00:17 by tcarlena          #+#    #+#             */
/*   Updated: 2020/06/08 17:11:25 by tcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_lstdelone(t_list *elem, t_list **lst)
{
	t_list	*elem_last;
	t_list	*elem_current;

	free(elem->content->line);
	free(elem->content);
	if (*lst == elem)
		*lst = elem->next;
	else
	{
		elem_current = *lst;
		while (elem_current && elem_current != elem)
		{
			elem_last = elem_current;
			elem_current = elem_current->next;
		}
		if (elem_current == elem)
			elem_last->next = elem->next;
	}
	free(elem);
}

int			ft_lstclear(t_list *lst)
{
	t_list	*last_elem;

	while (lst)
	{
		free(lst->content->line);
		free(lst->content);
		last_elem = lst;
		lst = lst->next;
		free(last_elem);
	}
	return (-1);
}

t_list		*ft_lstnew_fd(t_list **lst, int fd)
{
	t_list	*list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (!(list->content = malloc(sizeof(t_content))))
		return (NULL);
	if (!(list->content->line = malloc(sizeof(char) * BUFFER_SIZE)))
		return (NULL);
	list->content->fd = fd;
	list->content->len = 0;
	list->next = *lst;
	list->content->status = BUFFER_SIZE;
	*lst = list;
	return (list);
}

t_list		*ft_getelem_fd(t_list *lst, int fd)
{
	while (lst)
	{
		if (lst->content->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

char		*ft_strjoin_len(char const *s1, char const *s2, size_t len_s1,
		size_t len_s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (len_s1 + len_s2))))
		return (NULL);
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
