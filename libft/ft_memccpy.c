/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:43 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:46 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*td;
	unsigned char	*ts;
	unsigned char	uc;
	size_t			i;

	i = 0;
	uc = c;
	td = (unsigned char *)dst;
	ts = (unsigned char *)src;
	while (i < n)
	{
		td[i] = ts[i];
		if (ts[i] == uc)
		{
			return (&td[i + 1]);
		}
		i++;
	}
	return (NULL);
}
