/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/10/31 15:46:34 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"
#include <stdio.h>

int			rt_checkrgbpos(t_env *e, int red)
{
	int end;

	if (ft_strncmp(e->scene[red + 2], "\tpos:(", 6) != 0 || \
			ft_strncmp(e->scene[red + 3], "\trgb:(", 6) != 0)
		return (0);
	end = 6;
	e->items[e->citem].pos.x = ft_atoicount(e->scene[red + 2], &end);
	e->items[e->citem].pos.y = ft_atoicount(e->scene[red + 2], &end);
	e->items[e->citem].pos.z = ft_atoicount(e->scene[red + 2], &end);
	if (e->scene[red + 2][end] != ')')
		return (0);
	end = 6;
	e->items[e->citem].colour.red = ft_atoicount(e->scene[red + 3], &end);
	e->items[e->citem].colour.green = ft_atoicount(e->scene[red + 3], &end);
	e->items[e->citem].colour.blue = ft_atoicount(e->scene[red + 3], &end);
	if (e->scene[red + 3][end] != ')')
		return (0);
	return (1);
}

int			rt_makecylcone(t_env *e, int *red, int type)
{
	int end;

	e->items[e->citem].type = type;
	if (ft_strcmp(e->scene[*red + 1], "{") != 0 || \
			ft_strcmp(e->scene[*red + 7], "}") != 0)
		return (0);
	if (rt_checkrgbpos(e, *red) == 0 || \
			ft_strncmp(e->scene[*red + 4], "\tdir:(", 6))
		return (0);
	end = 6;
	e->items[e->citem].dir.x = ft_atoicount(e->scene[*red + 4], &end);
	e->items[e->citem].dir.y = ft_atoicount(e->scene[*red + 4], &end);
	e->items[e->citem].dir.z = ft_atoicount(e->scene[*red + 4], &end);
	if (e->scene[*red + 4][end] != ')')
		return (0);
	if ((ft_strncmp(e->scene[*red + 5], "\tsize: ", 7) != 0) ||\
		(ft_strncmp(e->scene[*red + 6], "\treflect: ", 10) != 0))
		return (0);
	end = 7;
	e->items[e->citem].size = ft_atoicount(e->scene[*red + 5], &end);
	end = 10;
	e->items[e->citem].reflection = ft_atoicount(e->scene[*red + 6], &end);
	e->citem++;
	*red += 8;
	return (1);
}

int			rt_makesphere(t_env *e, int *red)
{
	int end;

	e->items[e->citem].type = SPHERE;
	if (ft_strcmp(e->scene[*red + 1], "{") != 0 || \
			ft_strcmp(e->scene[*red + 6], "}") != 0)
		return (0);
	if (rt_checkrgbpos(e, *red) == 0)
		return (0);
	if (ft_strncmp(e->scene[*red + 4], "\tradius: ", 9) != 0 || \
			ft_strncmp(e->scene[*red + 5], "\treflect: ", 10) != 0)
		return (0);
	end = 9;
	e->items[e->citem].size = ft_atoicount(e->scene[*red + 4], &end);
	end = 10;
	e->items[e->citem].reflection = ft_atoicount(e->scene[*red + 5], &end);
	e->citem++;
	*red += 7;
	return (1);
}

int			rt_makeplane(t_env *e, int *red)
{
	int end;

	e->items[e->citem].type = PLANE;
	if (ft_strcmp(e->scene[*red + 1], "{") != 0 || \
			ft_strcmp(e->scene[*red + 5], "}") != 0)
		return (0);
	if (rt_checkrgbpos(e, *red) == 0)
		return (0);
	if (ft_strncmp(e->scene[*red + 4], "\tdir:(", 6))
		return (0);
	end = 6;
	e->items[e->citem].dir.x = ft_atoicount(e->scene[*red + 4], &end);
	e->items[e->citem].dir.y = ft_atoicount(e->scene[*red + 4], &end);
	e->items[e->citem].dir.z = ft_atoicount(e->scene[*red + 4], &end);
	if (e->scene[*red + 4][end] != ')')
		return (0);
	e->citem++;
	*red += 6;
	return (1);
}

int			rt_makelight(t_env *e, int *red)
{
	int end;

	if (ft_strcmp(e->scene[*red + 1], "{") != 0 || \
			ft_strcmp(e->scene[*red + 4], "}") != 0)
		return (0);
	if (ft_strncmp(e->scene[*red + 2], "\tpos:(", 6) != 0 || \
			ft_strncmp(e->scene[*red + 3], "\trgb:(", 6) != 0)
		return (0);
	end = 6;
	e->lights[e->culight].pos.x = ft_atoicount(e->scene[*red + 2], &end);
	e->lights[e->culight].pos.y = ft_atoicount(e->scene[*red + 2], &end);
	e->lights[e->culight].pos.z = ft_atoicount(e->scene[*red + 2], &end);
	if (e->scene[*red + 2][end] != ')')
		return (0);
	end = 6;
	e->lights[e->culight].colour.red = ft_atoicount(e->scene[*red + 3], &end);
	e->lights[e->culight].colour.green = ft_atoicount(e->scene[*red + 3], &end);
	e->lights[e->culight].colour.blue = ft_atoicount(e->scene[*red + 3], &end);
	if (e->scene[*red + 3][end] != ')')
		return (0);
	e->culight++;
	*red += 5;
	return (1);
}
