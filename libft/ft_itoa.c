/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/30 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		negative_divisor(unsigned int nb)
{
	long int	d;

	d = 10;
	while (nb / d)
		d *= 10;
	d /= 10;
	return (d);
}

static long int		find_divisor(int nb)
{
	long int d;

	if (nb < 0)
		return (negative_divisor((unsigned int)-nb));
	d = 10;
	while (nb / d)
		d *= 10;
	d /= 10;
	return (d);
}

static char			*ft_itoalloc(int n)
{
	char *str;

	if (n >= 0)
		str = ft_stralloc(ft_numcount((unsigned int)n));
	if (n < 0)
	{
		str = ft_stralloc(ft_numcount((unsigned int)-n * 10));
		if (str == NULL)
			return (NULL);
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

char				*ft_itoa(int n)
{
	char			*str;
	unsigned int	un;
	long int		d;
	int				i;

	un = n;
	i = 0;
	d = find_divisor(n);
	str = ft_itoalloc(n);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		un = -n;
	}
	while (d > 0)
	{
		str[i++] = un / d + '0';
		un = un - ((un / d) * d);
		d /= 10;
	}
	str[i] = '\0';
	return (str);
}
