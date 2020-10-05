/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 00:06:36 by tcarlena          #+#    #+#             */
/*   Updated: 2020/06/08 16:59:13 by tcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		id;

	int fd = open("1.txt", O_RDONLY);
	int fd_2 = open("2.txt", O_RDONLY);
	// fd = 42;
	// fd = 1;
	id = 0;
	line = "";
	int flag = 1;
	// while ((id = get_next_line(flag == 1 ? fd : fd, &line))>0)
	while ((id = get_next_line(flag == 1 ? fd : fd_2, &line)) > 0)
	{
		// printf("|gnl| %2d |fd| %2d |str| %s\n", id, flag == 1 ? fd : fd, line);
		printf("|gnl| %2d |fd| %2d |str| %s\n", id, flag == 1 ? fd : fd_2, line);
		if (flag == 1)
			flag = 2;
		else
			flag = 1;
		// free(line);
	}
	// printf("|gnl| %2d |fd| %2d |str| %s\n", id, flag == 1 ? fd : fd, line);
	printf("|gnl| %2d |fd| %2d |str| %s\n", id, flag == 1 ? fd : fd_2, line);
	// free(line);
	return (0);
}
