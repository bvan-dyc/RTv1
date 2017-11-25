/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:21:50 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:21:53 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**map;
	int		wc;
	int		y;
	int		x;

	wc = ft_wordcount((char *)s, c);
	map = ft_mapalloc(wc + 1, (int)ft_strlen((char *)s));
	if (map == NULL)
		return (NULL);
	y = 0;
	while (wc > 0)
	{
		if (*s != '\0' && *s != c && wc--)
		{
			x = 0;
			while (*s != '\0' && *s != c)
			{
				map[y][x++] = *s++;
			}
			map[y++][x] = '\0';
		}
		s++;
	}
	map[y] = NULL;
	return (map);
}
