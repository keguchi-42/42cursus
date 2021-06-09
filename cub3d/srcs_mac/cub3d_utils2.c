/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:10:59 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 11:37:43 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

int	this_is_worldmap(char *line)
{
	int	i;

	i = 0;
	if (!*line)
		return (-1);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strlen_path(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != ' ')
		i++;
	return (i);
}

char	*ft_strdup_path(char *line, int num)
{
	char	*swap;
	int		size;
	int		i;

	check_path_space(line, num);
	ft_skipspace(line, &num);
	size = 0;
	i = 0;
	size = ft_strlen_path(line + num);
	swap = (char *)malloc((size + 1) * sizeof(char));
	if (!(swap))
		return (NULL);
	while (i < size)
	{
		swap[i] = line[i + num];
		i++;
	}
	swap[i] = '\0';
	return (swap);
}
