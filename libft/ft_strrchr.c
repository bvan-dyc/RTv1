/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:06:52 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/30 16:06:57 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sav;

	sav = NULL;
	while (*s)
	{
		if (*s == (char)c)
			sav = (char *)s;
		s++;
	}
	if (c == '\0')
		sav = (char *)s;
	return (sav);
}
