/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:04:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/23 13:47:26 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check(char *buff, char **leftovers)
{
	int		i;
	int		j;
	char	*lo;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && i < BUFF_SIZE)
		i++;
	if (buff[i] == '\n')
	{
		if (!(lo = (char*)malloc(sizeof(*lo) * (BUFF_SIZE - i))))
			return (-1);
		while (++i <= BUFF_SIZE && buff[i] != '\0')
		{
			printf("i = %d\n", i);
			lo[j++] = buff[i];
			*leftovers = ft_strdup(lo);
		}
//		printf("i - j = %d\n", i - j);
		return (i - j);//			means there is a \n
	}
	return (-1);//				means there's not a \n
}

int			gnl(const int fd)
{
	static char		*leftovers;
	char			buff[BUFF_SIZE + 1];
	char			*stock;
	int				res;
	int				i;

	res = read(fd, buff, BUFF_SIZE);
	i = check(buff, &leftovers);
//	printf("???   %s\n", stock);
	if (!(stock = (char*)malloc(4096)))
		return (-1);
	printf("leftovers = %s\n", leftovers);
	if (leftovers != NULL)
	{
		stock = ft_strcpy(stock, leftovers);
		printf("new stock = %s\n", stock);
	}
	while (i != -2)
	{
		printf("leftovers? = %s\n", leftovers);
		if (i != -1)// if there is a \n
		{
			printf("leftovers ??? = %s\n", leftovers);
			stock = ft_strncat(stock, buff, i - 1);
			printf("stock0 : \033[1;37m%s\033[0m\n", stock);
			free(stock);
			stock = NULL;
			return (0);
		}
		else
		{
			stock = ft_strcat(stock, buff);
			printf("stock : \033[1;37m%s\033[0m\n", stock);
		}
		res = read(fd, buff, BUFF_SIZE);
		i = check(buff, &leftovers);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;
	int		i;

	i = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	gnl(fd);
	printf("\n\t\033[0;32mS E P A R A T E\033[0m\n\n");
	gnl(fd);
	printf("\n\t\033[0;32mS E P A R A T E\033[0m\n\n");
	gnl(fd);
	printf("\n\t\033[0;32mS E P A R A T E\033[0m\n\n");
	gnl(fd);
	printf("\n\t\033[0;32mS E P A R A T E\033[0m\n\n");
	gnl(fd);
	return (0);
}


// reussis a recuperer la premiere ligne quelle que soit la taille de buffer
//
// next step is to keep la lecture en cours pour recuperer chaque ligne a chaque appel de la fonction
//
// go compile pour voir ce qu'il y a a faire
