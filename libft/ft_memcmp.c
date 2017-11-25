/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:43 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:46 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	char *d1;
	char *d2;

	d1 = (char *)s1;
	d2 = (char *)s2;
	while (len > 0 && *d1 == *d2)
	{
		d1++;
		d2++;
		len--;
	}
	if (len > 0)
		return ((unsigned char)*d1 - (unsigned char)*d2);
	else
		return (0);
}
