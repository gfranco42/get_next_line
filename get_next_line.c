/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:54:21 by gfranco           #+#    #+#             */
/*   Updated: 2018/07/29 09:40:39 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void			yolo(const int fd, char **line)
{
	static t_gnl	*begin_list;
	t_gnl		*new;

	begin_list = NUL;
	if (!begin_list)
	{
		while (fd != begin_list->fd && begin_list->next)
			begin_list = begin_list->next;
		if (begin_list->next == NULL)
		{
			if (!(new = (t_gnl*)malloc(sizeof(new))))
				return (-1);
			new = begin_list;
			new->fd = fd;
			new->next = NULL;
			begin_list->next = new;
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	if (fd > 0)
}
