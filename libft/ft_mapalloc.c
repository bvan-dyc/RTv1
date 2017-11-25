/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:43 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:46 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_mapalloc(int lines, int columns)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * lines);
	if (map == NULL)
		return (NULL);
	while (i < lines)
	{
		map[i] = (char *)malloc(sizeof(char) * columns);
		i++;
	}
	return (map);
}
