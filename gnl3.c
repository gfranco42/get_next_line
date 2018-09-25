/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:47:50 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/25 19:22:43 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl3(const int fd)
{
	static t_stock	stock;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	char			*new;
	int				res;

	res = 0;
	tmp = (char*)ft_memalloc(BUFF_SIZE + 1);
	res = read(fd, buff, BUFF_SIZE);
	tmp = ft_strcpy(tmp, buff);
	res = read(fd, buff, BUFF_SIZE);
	while (res != 0)
	{
		new = ft_strjoin(tmp, buff);
		res = read(fd, buff, BUFF_SIZE);
		if (res != 0)
		{
			ft_strdel(&tmp);
			tmp = ft_strjoin(new, buff);
			res = read(fd, buff, BUFF_SIZE);
			ft_strdel(&new);
			if (res == 0)
				new = ft_strjoin(tmp, buff);
		}
	}
	if (ft_strcmp(tmp, new) > 0)
		stock.hold = ft_strsplit(tmp, '\n');
	else
	{
		stock.hold = ft_strsplit(new, '\n');
		printf("c\n");
	}
	printf("z\n");
	printf("%s\n", stock.hold[0]);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	gnl3(fd);
	printf("\n\n\033[1;37mSEPARATION\033[0m\n\n");
}
