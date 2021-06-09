/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:46:17 by keguchi           #+#    #+#             */
/*   Updated: 2020/07/11 20:52:59 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (str1 < str2)
		ft_memcpy(str1, str2, n);
	else
	{
		while (n > 0)
		{
			str1[n - 1] = str2[n - 1];
			n--;
		}
	}
	return (str1);
}
