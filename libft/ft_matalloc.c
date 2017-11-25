/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:43 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:46 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_matalloc(int lines, int columns)
{
	int **mat;
	int	i;

	i = 0;
	mat = (int **)malloc(sizeof(int *) * lines);
	while (i < lines)
	{
		mat[i] = (int *)malloc(sizeof(int) * columns);
		i++;
	}
	if (mat == NULL)
		return (NULL);
	return (mat);
}
