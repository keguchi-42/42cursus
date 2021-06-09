/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:08:16 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 11:45:41 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	for_error(int fd, char **line)
{
	if (!line || fd < 0 || 1 <= 0 || fd > 1024)
		return (1);
	if (fd == 1 || fd == 2)
		return (1);
	return (0);
}

static int	reading(char **line, char *tmp, char **save, int i)
{
	if (!*save)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = ft_strchr(*save, '\n');
	if (i >= 0)
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

static void	save_line(char *buf, char *tmp, char **save, int fd)
{
	if (!save[fd])
		save[fd] = ft_strdup("");
	tmp = ft_strjoin(save[fd], buf);
	free(save[fd]);
	save[fd] = ft_strdup(tmp);
	free(tmp);
}

int	get_next_line(int fd, char **line)
{
	char		*tmp;
	char		buf[2];
	static char	*save[1024];
	int			read_len;
	int			i;

	tmp = NULL;
	if (for_error(fd, line))
		return (-1);
	read_len = read(fd, buf, 1);
	while (read_len > 0)
	{
		buf[read_len] = '\0';
		save_line(buf, tmp, save, fd);
		i = ft_strchr(save[fd], '\n');
		if (i >= 0)
			break ;
		read_len = read(fd, buf, 1);
	}
	if (read_len < 0)
		return (-1);
	return (reading(line, tmp, &(save[fd]), i));
}
