/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:15:22 by bvan-dyc          #+#    #+#             */
/*   Updated: 2016/03/26 19:42:04 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../Includes/get_next_line.h"

static char		*join_next_line(char *dest, char *src)
{
	char		*tmp;

	if (!dest && !src)
		return (NULL);
	else if (!dest)
		tmp = ft_strdup(src);
	else if (!src)
		tmp = ft_strdup(dest);
	else
		tmp = ft_strjoin(dest, src);
	ft_strdel(&dest);
	return (tmp);
}

static void		buff_cutter(char **tbuff, char **line)
{
	*line = ft_strsub(*tbuff, '\0', ft_strchr(*tbuff, '\n') - *tbuff);
	ft_strcpy(*tbuff, ft_strchr(*tbuff, '\n') + 1);
}

static int		read_next_line(int fd, char **line, char **tbuff)
{
	int			red;
	char		buff[BUFF_SIZE + 1];

	while ((red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		tbuff[fd] = join_next_line(tbuff[fd], buff);
		if (!tbuff[fd])
			return (-1);
		if (ft_strchr(tbuff[fd], '\n'))
		{
			buff_cutter(&(tbuff[fd]), line);
			return (1);
		}
	}
	return (red);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tbuff[FD_MAX];
	int			red;

	if (line == NULL || fd < 0)
		return (-1);
	if (tbuff[fd] && *tbuff[fd] && (ft_strchr(tbuff[fd], '\n')))
	{
		buff_cutter(&(tbuff[fd]), line);
		return (1);
	}
	red = read_next_line(fd, line, tbuff);
	if (red == -1 || red == 1)
		return (red);
	if (tbuff[fd] && *(tbuff[fd]))
	{
		*line = ft_strdup(tbuff[fd]);
		ft_strdel(&(tbuff[fd]));
		return (1);
	}
	return (0);
}
