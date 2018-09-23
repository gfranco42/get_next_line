/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:58:33 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/19 19:07:00 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>




int		main(int ac, char **av)
{
	char		buff[BUFF_SIZE + 1];
	char		*str;
	char		*last = NULL;
	int			fd = 0;
	int			res = 0;
	int			len = 0;
	int			i = 0;


	if (!(str = (char*)malloc(sizeof(*str) * 4097)))
		return (0);
	fd = open(av[1], O_RDONLY);

	while (i++ < 3)
	{
		res = read(fd, buff, BUFF_SIZE);
		str = ft_strcat(str, buff);
		printf("%s\n", str);
	}

	close(fd);
	return (0);
}
