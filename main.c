/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:30:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/10/10 14:33:50 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd;
	int		res;
	char	*line;

	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	res = get_next_line(fd, &line);

	return (0);
}
