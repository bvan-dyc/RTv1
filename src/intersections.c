/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/10/31 15:46:52 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

int		rt_intersectsphere(t_ray *r, t_item *s, float *t)
{
	t_inter m;

	m.ret = FALSE;
	m.dist = rt_vectorsub(&r->start, &s->pos);
	m.a = rt_vecdot(&r->dir, &r->dir);
	m.b = 2 * rt_vecdot(&r->dir, &m.dist);
	m.c = rt_vecdot(&m.dist, &m.dist) - (s->size * s->size);
	m.discr = m.b * m.b - 4 * m.a * m.c;
	if (m.discr < 0)
		m.ret = FALSE;
	m.t0 = (-m.b + sqrtf(m.discr)) / (2);
	m.t1 = (-m.b - sqrtf(m.discr)) / (2);
	if (m.t0 > m.t1)
		m.t0 = m.t1;
	if ((m.t0 > 0.001) && (m.t0 < *t))
	{
		*t = m.t0;
		m.ret = TRUE;
	}
	else
		m.ret = FALSE;
	return (m.ret);
}

int		rt_intersectcone(t_ray *r, t_item *c, float *t)
{
	t_inter m;

	m.dist = rt_vectorsub(&r->start, &c->pos);
	rt_vectornorm(&c->dir);
	m.a = rt_vecdot(&r->dir, &r->dir) - (1 + pow(tan(c->size), 2)) *
		pow(rt_vecdot(&r->dir, &c->dir), 2);
	m.b = 2 * (rt_vecdot(&r->dir, &m.dist) - (1 + pow(tan(c->size), 2))
		* rt_vecdot(&r->dir, &c->dir) * rt_vecdot(&m.dist, &c->dir));
	m.c = rt_vecdot(&m.dist, &m.dist) - (1 +
		pow(tan(c->size), 2)) * pow(rt_vecdot(&m.dist, &c->dir), 2);
	m.discr = m.b * m.b - 4 * m.a * m.c;
	if (m.discr < 0)
		return (FALSE);
	m.t0 = (-m.b + sqrtf(m.discr)) / (2 * m.a);
	m.t1 = (-m.b - sqrtf(m.discr)) / (2 * m.a);
	if (m.t0 > m.t1)
		m.t0 = m.t1;
	m.ret = TRUE;
	if ((m.t0 > 0.001) && (m.t0 < *t))
		*t = m.t0;
	else
		m.ret = FALSE;
	r->dist = m.dist;
	return (m.ret);
}

int		rt_intersectcylinder(t_ray *r, t_item *c, float *t)
{
	t_inter m;

	m.dist = rt_vectorsub(&r->start, &c->pos);
	rt_vectornorm(&c->dir);
	m.a = rt_vecdot(&r->dir, &r->dir) - pow(rt_vecdot(&r->dir, &c->dir), 2);
	m.b = 2 * (rt_vecdot(&r->dir, &m.dist) -
		(rt_vecdot(&r->dir, &c->dir) * rt_vecdot(&m.dist, &c->dir)));
	m.c = rt_vecdot(&m.dist, &m.dist) -
		pow(rt_vecdot(&m.dist, &c->dir), 2) - c->size * c->size;
	m.discr = m.b * m.b - 4 * m.a * m.c;
	if (m.discr < 0)
		return (FALSE);
	m.t0 = (-m.b + sqrtf(m.discr)) / (2 * m.a);
	m.t1 = (-m.b - sqrtf(m.discr)) / (2 * m.a);
	if (m.t0 > m.t1)
		m.t0 = m.t1;
	if ((m.t0 > 0.001) && (m.t0 < *t))
	{
		*t = m.t0;
		m.ret = TRUE;
	}
	else
		m.ret = FALSE;
	r->dist = m.dist;
	return (m.ret);
}

int		rt_intersectplane(t_ray *r, t_item *p, float *t)
{
	double		denom;

	denom = ((rt_vecdot(&p->dir, &p->pos) -
			rt_vecdot(&p->dir, &r->start)) / rt_vecdot(&p->dir, &r->dir));
	if (denom < 0.0001)
		return (FALSE);
	*t = denom;
	if (t >= 0)
		return (TRUE);
	return (FALSE);
}
