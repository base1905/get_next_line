/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:26:10 by tcarlena          #+#    #+#             */
/*   Updated: 2020/06/08 15:36:45 by tcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct			s_content
{
	char	*line;
	size_t	len;
	int		fd;
	int		status;
}						t_content;

typedef struct			s_list
{
	t_content		*content;
	struct s_list	*next;
}						t_list;

int						get_next_line(int fd, char **line);
int						ft_lstclear(t_list *lst);
void					ft_lstdelone(t_list *elem, t_list **lst);
char					*ft_strjoin_len(char const *s1, char const *s2,
							size_t len_s1, size_t len_s2);
t_list					*ft_getelem_fd(t_list *lst, int fd);
t_list					*ft_lstnew_fd(t_list **lst, int fd);

#endif
