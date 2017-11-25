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

int		ft_atoicount(const char *str, int *i)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t'
	|| str[*i] == '\f' || str[*i] == '\v' || str[*i] == '\r'
	|| str[*i] == ',')
		(*i)++;
	if (str[*i] == '-')
		sign = -1;
	while (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		nb *= 10;
		nb += str[*i] - '0';
		(*i)++;
	}
	return (nb * sign);
}
