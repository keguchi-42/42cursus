/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:51:34 by keguchi           #+#    #+#             */
/*   Updated: 2020/07/18 15:17:57 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
		return (&tmp[i]);
	}
	while (tmp[i] != cc)
	{
		if (tmp[i] == '\0')
			return (NULL);
		i++;
	}
	return (&tmp[i]);
}
