/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:22:43 by bvan-dyc          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:46 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(const char *str, char c)
{
	int ws;

	ws = 0;
	while (*str)
	{
		if (*str && *str != c)
			ws++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (ws);
}
