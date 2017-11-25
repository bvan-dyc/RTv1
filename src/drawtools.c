/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/10/31 15:05:27 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

void	rt_rayinit(t_ray *ray, int x, int y, t_env *e)
{
	ray->red = 0;
	ray->green = 0;
	ray->blue = 0;
	ray->level = 0;
	ray->start.x = e->campos.x - WIN_W / 2 + x;
	ray->start.y = e->campos.y - WIN_H / 2 + y;
	ray->start.z = e->campos.z;
	ray->dir.x = e->camdir.x;
	ray->dir.y = e->camdir.y;
	ray->dir.z = e->camdir.z;
}

void	rt_lambert(t_env *e, t_ray *ray, t_ray *lightray, t_light currlight)
{
	if (lightray->inshadow == false)
	{
		e->lambert = rt_vecdot(&lightray->dir, &e->norm);
		printf("lambert %f\n", e->lambert);
		ray->red += e->lambert * (currlight.colour.red / 255) \
		* (e->items[e->citem].colour.red / 255);
		ray->green += e->lambert * (currlight.colour.green / 255) \
		* (e->items[e->citem].colour.green / 255);
		ray->blue += e->lambert * (currlight.colour.blue / 255) \
		* (e->items[e->citem].colour.blue / 255);
	}
}

void	rt_copylight(t_env *e, t_light *currlight, int j)
{
	currlight->pos.x = e->lights[j].pos.x;
	currlight->pos.y = e->lights[j].pos.y;
	currlight->pos.z = e->lights[j].pos.z;
	currlight->colour.red = e->lights[j].colour.red;
	currlight->colour.green = e->lights[j].colour.green;
	currlight->colour.blue = e->lights[j].colour.blue;
}
