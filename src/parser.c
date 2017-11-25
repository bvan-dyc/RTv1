/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/11/07 16:11:28 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

int			rt_parsecamera(t_env *e, int *red)
{
	int end;

	if (ft_strcmp(e->scene[*red + 1], "{") != 0 || \
			ft_strcmp(e->scene[*red + 4], "}") != 0)
		return (0);
	if (ft_strncmp(e->scene[*red + 2], "\tpos:(", 6) != 0 || \
			ft_strncmp(e->scene[*red + 3], "\tdir:(", 6) != 0)
		return (0);
	end = 6;
	e->campos.x = ft_atoicount(e->scene[*red + 2], &end);
	e->campos.y = ft_atoicount(e->scene[*red + 2], &end);
	e->campos.z = ft_atoicount(e->scene[*red + 2], &end);
	if (e->scene[*red + 2][end] != ')')
		return (0);
	end = 6;
	e->camdir.x = ft_atoicount(e->scene[*red + 3], &end);
	e->camdir.y = ft_atoicount(e->scene[*red + 3], &end);
	e->camdir.z = ft_atoicount(e->scene[*red + 3], &end);
	if (e->scene[*red + 3][end] != ')')
		return (0);
	*red += 5;
	return (1);
}

static int	rt_pfcore(t_env *e, int *red)
{
	if ((ft_strcmp(e->scene[*red], "Cone") == 0) && e->ss > *red + 7)
	{
		if (rt_makecylcone(e, red, CONE) == 0)
			return (0);
	}
	else if ((ft_strcmp(e->scene[*red], "Cylinder") == 0) && e->ss > *red + 7)
	{
		if (rt_makecylcone(e, red, CYL) == 0)
			return (0);
	}
	else if ((ft_strcmp(e->scene[*red], "Plane") == 0) && e->ss > *red + 5)
	{
		if (rt_makeplane(e, red) == 0)
			return (0);
	}
	else if ((ft_strcmp(e->scene[*red], "Sphere") == 0) && e->ss > *red + 6)
	{
		if (rt_makesphere(e, red) == 0)
			return (0);
	}
	else
		*red = *red + 1;
	return (1);
}

static int	rt_parseforms(t_env *e, int red)
{
	if ((ft_strcmp(e->scene[red], "Camera") == 0) && e->ss > red + 4)
	{
		if (rt_parsecamera(e, &red) == 0)
			return (0);
	}
	while (red < e->ss - 1)
	{
		if ((ft_strcmp(e->scene[red], "Light") == 0) && e->ss > red + 4)
		{
			if (rt_makelight(e, &red) == 0)
				return (0);
		}
		else
		{
			if (rt_pfcore(e, &red) == 0)
				return (0);
		}
	}
	return (1);
}

void		analyze_scene(t_env *e)
{
	int i;

	i = 0;
	while (i < e->ss)
	{
		if (ft_strcmp(e->scene[i], "Sphere") == 0)
			e->numitems++;
		else if (ft_strcmp(e->scene[i], "Cylinder") == 0)
			e->numitems++;
		else if (ft_strcmp(e->scene[i], "Cone") == 0)
			e->numitems++;
		else if (ft_strcmp(e->scene[i], "Plane") == 0)
			e->numitems++;
		else if (ft_strcmp(e->scene[i], "Light") == 0)
			e->numlights++;
		i++;
	}
	e->items = (t_item *)malloc((e->numitems + 1) * sizeof(t_item));
	e->lights = (t_light *)malloc((e->numlights + 1) * sizeof(t_light));
}

int			parsecore(t_env *e)
{
	analyze_scene(e);
	if (rt_parseforms(e, STARTOBJECTS) == 0)
		rt_error(3);
	return (0);
}
