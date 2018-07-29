/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:55:30 by gfranco           #+#    #+#             */
/*   Updated: 2018/07/26 13:29:15 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 893

typedef struct		s_gnl
{
	int				fd;
	char			*rest;
	struct s_gnl	*next;
}					t_gnl;

int		get_next_line(const int fd, char **line);

//PROTO A RETIRER ===>

char	*ft_file_cpy(int fd);

#endif
