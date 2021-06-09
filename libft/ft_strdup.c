/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:52:50 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:34:04 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*swap;
	int		size;

	size = ft_strlen(src);
	swap = (char *)malloc((size + 1) * sizeof(char));
	if (!swap)
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
