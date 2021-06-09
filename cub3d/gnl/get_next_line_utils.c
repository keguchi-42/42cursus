/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:08:24 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/05 02:53:21 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	cc;
	int		i;

	tmp = (char *)s;
	cc = (char)c;
	i = 0;
	if (cc == '\0')
	{
		while (tmp[i] != '\0')
			i++;
		return (i);
	}
	while (tmp[i] != cc)
	{
		if (tmp[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*swap;
	int		size;

	size = ft_strlen(src);
	swap = (char *)malloc((size + 1) * sizeof(char));
	if (!(swap))
		return (NULL);
	size = 0;
	while (src[size])
	{
		swap[size] = src[size];
		size++;
	}
	swap[size] = '\0';
	return (swap);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		i;
	int		j;
	char	*result;

	count = 0;
	i = 0;
	j = 0;
	count = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc((count + 1) * sizeof(char));
	if (!(result))
		return (NULL);
	while (s1[j] != '\0')
		result[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
