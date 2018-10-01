/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:30:47 by gfranco           #+#    #+#             */
/*   Updated: 2018/10/01 17:50:34 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

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

//	printf("\033[1;37mstock: %s\033[0m\n", *stock);
	tmp = ft_strchr(*stock, '\n');
//	printf("\033[1;37mtmp: %s\033[0m\n", tmp);
//	printf("\033[1;37mlen tmp: %zu\033[0m\n", ft_strlen(tmp));
/*	if (ft_strlen(tmp) <= 1)
	{
		*line = ft_strdup(*stock);
		return (0);
	}*/
	if (tmp[0] == '\n')
	{
		*line = ft_strndup(*stock);
		ft_strcpy(*stock, tmp + 1);
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

	if (fd < 0 || BUFF_SIZE < 1 || !line || !fd)
		return (-1);
	if (!stock)
		stock = ft_strnew(0);
	while (!(ft_strchr(stock, '\n')))
	{
		if ((res = read(fd, buff, BUFF_SIZE)) == 0)
			return (0);
		if (res == -1)
			return (-1);
		buff[res] = '\0';
		tmp = ft_strjoin(stock, buff);
		free(stock);
		stock = tmp;
	}
	return (ft_ret_value(&stock, line));
}
/*
int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i = -2;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (i != 0 && i != -1)
	{
		i = get_next_line(fd, &line);
		printf("\033[1;37m%s\033[0m\n", line);
		printf("\033[1;35m%d\033[0m\n", i);
		free(line);
		line = NULL;
	}
//	get_next_line(fd, &line);
//	printf("\033[1;37m%s\033[0m\n", line);
//	free(line);
//	line = NULL;
	close(fd);
	return (0);
}*/
