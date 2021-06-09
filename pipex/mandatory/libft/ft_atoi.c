/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 00:33:54 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:37:01 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			pm;

	num = 0;
	pm = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pm = -1;
		str++;
	}
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		num = num + (*str - 48);
		num = num * 10;
		str++;
	}
	num = num / 10;
	num = num * pm;
	return (num);
}
