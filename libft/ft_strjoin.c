/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:21:50 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:21:53 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = (ft_strlen(s1)) + (ft_strlen(s2) + 1);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	if (!ft_strcat(str, s1))
		return (NULL);
	if (!ft_strcat(str, s2))
		return (NULL);
	return (str);
}
