/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:55:30 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/25 19:17:58 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdio.h>
# define BUFF_SIZE 4

typedef struct	s_stock
{
	char		**hold;
	int			j;
}				t_stock;

int		get_next_line(const int fd, char **line);

#endif
