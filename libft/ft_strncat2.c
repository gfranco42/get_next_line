/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:22:39 by gfranco           #+#    #+#             */
/*   Updated: 2018/09/27 12:40:11 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat2(char *s1, const char *s2, size_t m, size_t n)
{
	size_t	del;
	size_t	lvl;

	lvl = 0;
	del = m;
	while (s1[del])
	{
		s1[del] = '\0';
		del++;
	}
	s1[m] = s2[lvl];
	while (lvl < n && s2[lvl])
	{
		s1[m] = s2[lvl];
		m++;
		lvl++;
	}
	s1[m] = '\0';
	return (&s1[0]);
}
