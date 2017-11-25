/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findsign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/30 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findsign(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		else
			return (-1);
	}
	else if (str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		else
			return (1);
	}
	else if (ft_isdigit(str[i]))
		return (1);
	else
		return (0);
}
