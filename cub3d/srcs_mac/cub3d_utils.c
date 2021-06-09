/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:36:34 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 16:06:07 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(char *line, int *i)
{
	long int	num;

	num = 0;
	ft_skipspace(line, i);
	while (line[*i] != '\0' && line[*i] >= 48 && line[*i] <= 57)
	{
		num = num + (line[*i] - 48);
		num *= 10;
		(*i)++;
	}
	num /= 10;
	return (num);
}

void	ft_skipspace(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

void	skip_num(char *line, int *i, int *count)
{
	ft_skipspace(line, i);
	while (line[*i] != '\0' && line[*i] >= '0' && line[*i] <= '9')
	{
		(*i)++;
		(*count)++;
	}
}
