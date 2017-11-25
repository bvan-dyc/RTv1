/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:24:36 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:24:49 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*rts;

	rts = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (rts == NULL)
		return (NULL);
	else
		return (ft_strcpy(rts, str));
}
