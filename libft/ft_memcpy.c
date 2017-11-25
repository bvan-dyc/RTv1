/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:43 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:46 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *ss;
	char *sd;

	ss = (char *)src;
	sd = (char *)dest;
	while (n > 0)
	{
		*sd = *ss;
		sd++;
		ss++;
		n--;
	}
	return (dest);
}
