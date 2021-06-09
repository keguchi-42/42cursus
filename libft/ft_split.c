/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:50:59 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:31:24 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**for_free(char **str, int size)
{
	while (0 < size)
	{
		free(str[size]);
		size--;
	}
	free(str[size]);
	return (NULL);
}

static int	count_string(char *tmp, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tmp[i])
	{
		while (tmp[i] == c)
			i++;
		if (tmp[i] != '\0')
			count++;
		while (tmp[i] && tmp[i] != c)
			i++;
	}
	return (count);
}

static char	**get_string(char **str, char *tmp, char c)
{
	int	i;
	int	x;
	int	swap;

	i = 0;
	x = 0;
	while (tmp[i])
	{
		if (tmp[i] && tmp[i] != c)
		{
			swap = i;
			while (tmp[i] && tmp[i] != c)
				i++;
			str[x] = ft_substr(&tmp[swap], 0, i - swap);
			if (!str[x])
				return (for_free(str, x));
			x++;
		}
		if (!tmp[i])
			break ;
		i++;
	}
	str[x] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*tmp;
	int		count;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	count = count_string(tmp, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	return (get_string(str, tmp, c));
}
