/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:53:58 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:28:47 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		i;
	int		j;
	char	*result;

	count = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	count = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[j] != '\0')
		result[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
