/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:49:23 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/23 16:54:16 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char				*copy_swap(char *stock, char **leftovers)
{
	int				i;
	int				j;
	char			*tmp;

	i = -1;
	j = 0;
	if (!(tmp = (char*)malloc(4096)))
		return (NULL);
	while (*leftovers[++i] != '\n')
		stock[i] = *leftovers[i];
	
}
*/
int					check(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] != '\n')
	{
		if (buff[i] == '\0')
			return (-1);//		if there is NO '\n'
		i++;
	}
	return (i);//				if THERE IS a '\n'
}

int					gnl2(const int fd)
{
	static char		*leftovers;
	char			*stock;
	char			buff[BUFF_SIZE + 1];
	int				size;
	int				i;

	i = -1;
	if (!(stock = (char*)malloc(4096)))
		return(-1);
	if (leftovers != NULL)
	{
		stock = ft_strdup(leftovers);
		free(leftovers);
	}
//	printf("leftovers = %s\n", leftovers);
	while (i == -1)
	{
		size = read(fd, buff, BUFF_SIZE);
		if ((i = check(buff)) == -1)
			stock = ft_strcat(stock, buff);
	}
	stock = ft_strncat(stock, buff, i);
	if (i < BUFF_SIZE)
	{
		leftovers = ft_strdup(&buff[i + 1]);
	}
//	printf("final stock = %s\n", stock);
	free(stock);
	return (0);
}







int					main(int ac, char **av)
{
	int				fd;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	gnl2(fd);
	printf("\n\n\033[1;32mSEPARATION\033[0m\n\n");
	gnl2(fd);
}
