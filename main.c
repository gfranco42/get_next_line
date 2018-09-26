/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:58:33 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/26 13:31:04 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>




int		main(int ac, char **av)
{
	char		buff[BUFF_SIZE + 1];
	int			fd = 0;
	int			res = 0;

	fd = open(av[1], O_RDONLY);
	res = read(fd, buff, BUFF_SIZE);
	buff[res] = '\0';
	printf("%s\n", buff);

	return (0);
}
