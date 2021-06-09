/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:56:04 by keguchi           #+#    #+#             */
/*   Updated: 2020/08/13 15:04:04 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		for_error(int fd, char **line)
{
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (1);
	if (fd == 1 || fd == 2)
		return (1);
	return (0);
}

static int		reading(char **line, char *tmp, char **save, int i)
{
	if (!*save)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((i = ft_strchr(*save, '\n')) >= 0)
	{
		tmp = ft_strdup(*save);
		tmp[i] = '\0';
		*line = ft_strdup(tmp);
		free(*save);
		*save = ft_strdup(tmp + i + 1);
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	char		*tmp;
	char		*buf;
	static char	*save[1024];
	int			read_len;
	int			i;

	if (for_error(fd, line) ||
			(!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_len] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup("");
		tmp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = ft_strdup(tmp);
		free(tmp);
		if ((i = ft_strchr(save[fd], '\n')) >= 0)
			break ;
	}
	free(buf);
	if (read_len < 0)
		return (-1);
	return (reading(line, tmp, &(save[fd]), i));
}
