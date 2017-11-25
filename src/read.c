/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

static char	*makebuff(char *file, t_env *e)
{
	int		fd;
	char	*buff;
	char	*line;

	buff = ft_strnew(1);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		buff = rt_strjoin(buff, ft_strjoin(line, "\n"));
		free(line);
		e->ss++;
	}
	if (close(fd) == -1)
	{
		rt_error(3);
		return (NULL);
	}
	return (buff);
}

char		**makescene(t_env *e, char *file)
{
	int		x;
	int		i;
	int		y;
	char	**scene;
	char	*buff;

	buff = makebuff(file, e);
	if (!buff || !(scene = (char **)malloc(sizeof(char *) * (e->ss + 1))))
		return (NULL);
	i = 0;
	y = 0;
	while (buff[i] != '\0' && y < e->ss)
	{
		x = 0;
		if (!(scene[y] = (char *)malloc(sizeof(char) * ft_linelen(buff, i))))
			return (NULL);
		while (buff[i] != '\n' && buff[i] != '\0')
			scene[y][x++] = buff[i++];
		scene[y][x] = '\0';
		i++;
		y++;
	}
	free(buff);
	return (scene);
}
