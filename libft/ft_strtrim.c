/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:21:50 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:21:53 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	ss;
	unsigned int	se;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ss = 0;
	while (ss < len && (s[ss] == ' ' || s[ss] == '\t' || s[ss] == '\n'))
		ss++;
	if (ss == len)
		return (ft_strnew(len));
	se = len - 1;
	while (s[se] == ' ' || s[se] == '\t' || s[se] == '\n')
		se--;
	if (se - ss == len)
		return ((char *)s);
	len = se - ss + 1;
	return (ft_strsub((char const *)s, ss, len));
}
