/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/11/07 16:11:56 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

void			rt_envfreer(t_env *e)
{
	int k;

	k = 0;
	while (k < e->ss)
	{
		if (e->scene[k])
			free(e->scene[k]);
		k++;
	}
	if (e->mlx)
		free(e->mlx);
	if (e->scene)
		free(e->scene);
	if (e->items)
		free(e->items);
	if (e->items)
		free(e->lights);
	if (e)
		free(e);
}

void			shadow_print(t_env *e, int x, int y, char *s)
{
	mlx_string_put(e->mlx, e->win, x, y + 1, BLACK, s);
	mlx_string_put(e->mlx, e->win, x, y, WHITE, s);
}

void			pixel_put(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pos = (x * e->bits_per_pixel / 8) + (y * e->size_line);
		e->img[pos] = color;
		e->img[pos + 1] = color >> 8;
		e->img[pos + 2] = color >> 16;
	}
}

void			fill_image(t_env *e, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			pixel_put(e, x, y, color);
			x++;
		}
		y++;
	}
}
