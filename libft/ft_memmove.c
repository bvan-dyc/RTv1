/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:43 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:46 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	i = 0;
	if (ts1 > ts2)
	{
		while (n > i++)
			ts1[n - i] = ts2[n - i];
	}
	else
	{
		while (n > i)
		{
			ts1[i] = ts2[i];
			i++;
		}
	}
	return (s1);
}
