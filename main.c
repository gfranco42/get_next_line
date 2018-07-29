/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:58:33 by gfranco           #+#    #+#             */
/*   Updated: 2018/07/29 10:07:34 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fillit/includes/fillit.h"
#include <stdio.h>
#define BUFF_SIZE 7

int		main(int ac, char **av)
{
//	char		*str = NULL;
	char		 buff[BUFF_SIZE + 1];
	int			fd = 0;
	int			res = 0;
	int			len = 0;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		res = read(fd, buff, BUFF_SIZE);
		while (buff[len] != '\n')
			len++;
		printf("%d\n", len);
//		str = (char*)malloc(sizeof(str) * res);
//		ft_strncpy(str, buff, res);
	}
	return (0);
}
