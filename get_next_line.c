/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_yolo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:46:01 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/28 17:26:55 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

// 1/ strchr stock pour search un '\n'
// 2/ Si ya un \n return
//	  Sinon read
// 3/ join strchr + buff dans tmp
// 4/ free stock puis faire pointer stock sur tmp
// 5/ refaire



char		*ft_strndup(const char *stock)
{
	char	*line;
	int		i;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	line = (char*)ft_memalloc(i + 1);
	ft_strncpy(line, stock, i);
	return (line);
}

int			ft_ret_value(char **stock, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*stock, '\n');
	if (tmp[0] == '\n')
	{
		*line = ft_strndup(*stock);
		ft_strcpy(*stock, tmp + 1);
//		printf("stock 1: %s\n", *stock);
		return (1);
	}
	if (tmp[0] != '\n')
	{
		*line = ft_strdup(*stock);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stock = NULL;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	int			res;

	if (fd < -0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!stock)
		stock = ft_strnew(0);
//	printf("stock 1: %s\n", stock);
	while (!(ft_strchr(stock, '\n')))
	{
//		printf("stock 2: %s\n", stock);
		if ((res = read(fd, buff, BUFF_SIZE)) == 0)
			return (0);
		buff[res] = '\0';
		tmp = ft_strjoin(stock, buff);
//		printf("tmp: %s\n", tmp);
		free(stock);
		stock = tmp;
	}
//	printf("stock 3: %s\n", stock);
	return (ft_ret_value(&stock, line));
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("\033[1;37m%s\033[0m\n", line);
	free(line);
	line = NULL;
//	get_next_line(fd, &line);
//	printf("\033[1;37m%s\033[0m\n", line);
//	free(line);
//	line = NULL;
//	get_next_line(fd, &line);
//	printf("\033[1;37m%s\033[0m\n", line);
//	free(line);
//	line = NULL;
	close(fd);
	return (0);
}
