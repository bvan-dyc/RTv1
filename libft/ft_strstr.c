/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:25:02 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:25:07 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int x;

	i = 0;
	if (!*s1 && !*s2)
		return ((char *)s1);
	while (s1[i])
	{
		x = 0;
		while ((s1[i + x] == s2[x]) && s2[x])
			x++;
		if (s2[x] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
