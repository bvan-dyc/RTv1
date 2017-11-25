/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/30 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	i;
	int				nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = ft_findsign((char *)str);
	if (sign == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (ft_isdigit(str[i]))
		{
			nb *= 10;
			nb += str[i] - '0';
		}
		i++;
	}
	return (nb * sign);
}
