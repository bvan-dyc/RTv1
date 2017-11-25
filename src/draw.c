/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/10/31 15:13:22 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

void	rt_shadowdraw(t_env *e, float t, t_ray *lightray)
{
	int		k;

	k = 0;
	lightray->inshadow = false;
	while (k < e->numitems)
	{
		if (e->items[k].type == SPHERE && \
	rt_intersectsphere(lightray, &e->items[k], &t))
			lightray->inshadow = true;
		else if (e->items[k].type == CYL && \
	rt_intersectcylinder(lightray, &e->items[k], &t))
			lightray->inshadow = true;
		else if (e->items[k].type == CONE && \
	rt_intersectcone(lightray, &e->items[k], &t))
			lightray->inshadow = true;
		else if (e->items[k].type == PLANE && \
	rt_intersectplane(lightray, &e->items[k], &t))
			lightray->inshadow = true;
		if (lightray->inshadow == true)
			k = e->numitems;
		k++;
	}
}

void	rt_colordraw(t_env *e, t_ray *ray, float t)
{
	int			j;
	t_ray		*lightray;
	t_light		currlight;

	j = 0;
	lightray = (t_ray *)malloc(sizeof(t_ray));
	while (j < e->numlights)
	{
		rt_copylight(e, &currlight, j);
		ray->dist = rt_vectorsub(&currlight.pos, &ray->hitpoint);
		if (!(rt_vecdot(&e->norm, &ray->dist) <= 0))
		{
			t = sqrtf(rt_vecdot(&ray->dist, &ray->dist));
			if (!(t <= 0))
			{
				lightray->start = ray->hitpoint;
				lightray->dir = rt_vectorscale((1 / t), &ray->dist);
				rt_shadowdraw(e, t, lightray);
				rt_lambert(e, ray, lightray, currlight);
			}
		}
		j++;
	}
	free(lightray);
}

float	rt_intersectcore(t_env *e, t_ray *ray)
{
	int		i;
	float	t;

	i = 0;
	t = 20000;
	e->citem = -1;
	while (i < e->numitems)
	{
		if (e->items[i].type == SPHERE && \
	rt_intersectsphere(ray, &e->items[i], &t))
			e->citem = i;
		else if (e->items[i].type == CYL && \
	rt_intersectcylinder(ray, &e->items[i], &t))
			e->citem = i;
		else if (e->items[i].type == CONE && \
	rt_intersectcone(ray, &e->items[i], &t))
			e->citem = i;
		else if (e->items[i].type == PLANE && \
	rt_intersectplane(ray, &e->items[i], &t))
			e->citem = i;
		i++;
	}
	return (t);
}

void	rt_raytrace(t_env *e, t_ray *ray, float t)
{
	t_vector	dist;
	t_vector	temp;
	t_vector	temp2;

	ray->scaled = rt_vectorscale(t, &ray->dir);
	ray->hitpoint = rt_vectoradd(&ray->start, &ray->scaled);
	if (e->items[e->citem].type == SPHERE)
		e->norm = rt_vectorsub(&ray->hitpoint, &e->items[e->citem].pos);
	else if (e->items[e->citem].type == CYL || e->items[e->citem].type == CONE)
	{
		dist = rt_vectorsub(&ray->start, &e->items[e->citem].pos);
		temp = rt_vectorscale((rt_vecdot(&ray->dir, &e->items[e->citem].dir) * t
		+ rt_vecdot(&dist, &e->items[e->citem].dir)), &e->items[e->citem].dir);
		if (e->items[e->citem].type == CONE)
			temp = rt_vectorscale((1 + pow(tan(e->items[e->citem].size), 2)), \
			&temp);
		temp2 = rt_vectorsub(&ray->hitpoint, &e->items[e->citem].pos);
		e->norm = rt_vectorsub(&temp2, &temp);
	}
	else if (e->items[e->citem].type == PLANE)
		e->norm = e->items[e->citem].dir;
	rt_vectornorm(&e->norm);
	rt_colordraw(e, ray, t);
}

void	rt_draw(t_env *e)
{
	t_ray		*ray;
	int			x;
	int			y;
	float		t;

	ray = (t_ray *)malloc(sizeof(t_ray));
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			rt_rayinit(ray, x, y, e);
			t = rt_intersectcore(e, ray);
			if (e->citem != -1)
				rt_raytrace(e, ray, t);
			pixel_put(e, x, y, convert_rgb(ft_fmin(ray->red * 255, 255), \
	ft_fmin(ray->green * 255, 255), ft_fmin(ray->blue * 255, 255)));
			x++;
		}
		y++;
	}
	free(ray);
}
