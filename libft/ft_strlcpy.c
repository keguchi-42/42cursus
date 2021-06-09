/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:57:41 by keguchi           #+#    #+#             */
/*   Updated: 2020/07/17 23:42:15 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	if (!dest || !src)
		return (0);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	count = ft_strlen(src);
	if (!size)
		return (count);
	while (i < size - 1 && str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return (count);
}
