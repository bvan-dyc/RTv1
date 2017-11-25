/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:25:02 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:25:07 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	ls2;

	ls2 = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && ls2 <= n--)
	{
		if (!(ft_memcmp(s1++, s2, ls2)))
			return ((char *)s1 - 1);
	}
	return (NULL);
}
