/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:49:23 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/26 16:08:08 by gfranco          ###   ########.fr       */
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
char		*ft_strndup(const char *s1, int i)
{
	char	*tab;

	tab = (char*)ft_memalloc(i + 1);
	ft_strncat(tab, s1, i);
	return (tab);
}

int					check(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (-1);//		if there is NO '\n'
		i++;
	}
	return (i);//				if THERE IS a '\n'
}

int					get_next_line(const int fd, char **line)
{
	static char		*leftovers;
	char			*stock;
	char			*tmp;
	char			buff[BUFF_SIZE + 1];
	int				size;
	int				i;

	i = -1;
	stock = (char*)ft_memalloc(1);
	if (leftovers != NULL)
	{
//		printf("\033[1;31mleftovers before modif = %s\n\033[0m", leftovers);//		ROUGE ROUGE ROUGE
		i = check(leftovers);
		tmp = ft_strndup(leftovers, i);
		stock = ft_strjoin(stock, tmp);
		ft_strdel(&tmp);
//		stock = ft_strncat(stock, leftovers, i);
		leftovers = &leftovers[i + 1];
		if (i != -1)
		{
			*line = ft_strdup(stock);
//			printf("\033[0;35mstock = %s\033[0m", stock);
			ft_strdel(&stock);
			return (0);
		}
//		printf("\033[1;36mnew leftovers: %s\n\033[0m", leftovers);//				CIEL CIEL CIEL
//		printf("i1 = %d\n", i);
//		stock = ft_strdup(leftovers);
//		printf("\033[1;32mstock from leftovers: %s\n\033[0m", stock);//				VERT VERT VERT
	}
	while (i == -1)
	{
//		printf("THIS IS NOT A RESULT\n");
		size = read(fd, buff, BUFF_SIZE);
		buff[size] = '\0';
		if (size == 0)
			return (0);
//		printf("\033[1;33mBUFF = %s\n\033[0m", buff);//								JAUNE JAUNE JAUNE
//		printf("\033[1;33m%c, %c, %c, %c, %c, %c\n", buff[13], buff[14], buff[15], buff[16], buff[17], buff[19]);
		if ((i = check(buff)) == -1)
		{
//			printf("i2 = %d\n", i);
			stock = ft_strjoin(stock, buff);
		}
	}
	if (buff[i] == '\n' && buff[i + 1] != '\0')
	{
		leftovers = ft_strdup(&buff[i + 1]);
//		printf("\033[1;34mleftovers after fill = %s\n\033[0m", leftovers);//		BLEU BLEU BLEU
	}
//	printf("i3 = %d\n", i);
	tmp = ft_strndup(buff, i);
	stock = ft_strjoin(stock, tmp);
	ft_strdel(&tmp);
	*line = ft_strdup(stock);
//	printf("\033[1;37m%zu\033[0m\n", ft_strlen(stock));
//	printf("\033[1;35mfinal stock = %s\033[0m", stock);//							VIOLET VIOLET VIOLET
	ft_strdel(&stock);
	return (0);
}
/*

int					main(int ac, char **av)
{
	int				fd;
	char			*line;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	gnl2(fd, &line);
	printf("\033[1;37m%s\033[0m", line);
	gnl2(fd, &line);
	printf("\033[1;37m%s\033[0m", line);
	gnl2(fd, &line);
	printf("\033[1;37m%s\033[0m", line);
}

*/
//probleme lorsqu'il y a une ligne entiere qui passe dans leftovers
