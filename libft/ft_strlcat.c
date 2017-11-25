/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:12:03 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/30 16:12:04 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ld;
	size_t	ls;
	size_t	len;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	len = 0;
	if (ld > size)
	{
		return (size + ls);
	}
	while (src[len] != '\0' && ld + len + 1 < size)
	{
		dst[len + ld] = src[len];
		len++;
	}
	dst[ld + len] = '\0';
	return (ls + ld);
}
