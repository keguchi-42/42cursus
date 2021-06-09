/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 02:04:32 by keguchi           #+#    #+#             */
/*   Updated: 2020/07/18 15:05:04 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	cc;

	i = 0;
	tmp = (char *)s;
	cc = (char)c;
	while (tmp[i] != '\0')
		i++;
	if (cc == '\0')
		return (&tmp[i]);
	while (i >= 0)
	{
		if (tmp[i] == cc)
			return (&tmp[i]);
		i--;
	}
	return (NULL);
}
