/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:30:47 by gfranco           #+#    #+#             */
/*   Updated: 2018/10/09 11:50:34 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strndup(const char *stock)
{
	char		*line;
	int			i;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	line = (char*)ft_memalloc(i + 1);
	ft_strncpy(line, stock, i);
	return (line);
}

int				ft_ret_value(char **stock, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*stock, '\n');
	if (tmp[0] == '\n')
	{
		*line = ft_strndup(*stock);
		ft_strcpy(*stock, tmp + 1);
		return (1);
	}
	return (0);
}

int				short_return(int res, int fd, char **line)
{
	if (res == -1 || fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stock = NULL;
	char		buff[BUFF_SIZE + 1];
	int			res;

	if (!stock)
		stock = ft_strnew(0);
	while (!(ft_strchr(stock, '\n')))
	{
		res = read(fd, buff, BUFF_SIZE);
		if (res == -1 || (res == 0 && ft_strlen(stock) == 0))
			return (short_return(res, fd, line));
		buff[res] = '\0';
		stock = ft_strjoinclr(stock, buff);
		if (res == 0 && ft_strlen(stock) > 0)
		{
			*line = ft_strndup(stock);
			ft_strdel(&stock);
			return (1);
		}
	}
	return (ft_ret_value(&stock, line));
}
/*
int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		count = 0;
	int		i = 0;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("\033[1;37m%s\033[0m\n", line);
		printf("\033[1;35m%d\033[0m\n", i);
		count++;
		free(line);
		line = NULL;
	}
	printf("count = %d\n", count);
//	get_next_line(fd, &line);
//	printf("\033[1;37m%s\033[0m\n", line);
//	free(line);
//	line = NULL;
	close(fd);
	return (0);
}*/
