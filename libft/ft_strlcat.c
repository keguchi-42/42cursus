/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:54:38 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:34:44 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	re;

	a = 0;
	b = 0;
	c = 0;
	re = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0')
		b++;
	if (size <= a)
		re = b + size;
	else
		re = a + b;
	while (a + 1 < size && src[c] != '\0')
	{
		dest[a] = src[c];
		a++;
		c++;
	}
	dest[a] = '\0';
	return (re);
}
