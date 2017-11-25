/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectortools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/10/31 14:36:23 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

t_vector	rt_vectorsub(t_vector *v1, t_vector *v2)
{
	t_vector res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	return (res);
}

void		rt_vectornorm(t_vector *v)
{
	double	n;

	n = 1.0 / sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

float		rt_vecdot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector	rt_vectorscale(float c, t_vector *v)
{
	t_vector res;

	res.x = v->x * c;
	res.y = v->y * c;
	res.z = v->z * c;
	return (res);
}

t_vector	rt_vectoradd(t_vector *v1, t_vector *v2)
{
	t_vector res;

	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	return (res);
}
