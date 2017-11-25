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

char	*rt_strjoin(char *s1, char *s2)
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
	free(s1);
	free(s2);
	return (str);
}
