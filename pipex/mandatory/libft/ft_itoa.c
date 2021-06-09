/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:10:50 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:44:41 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	add_minus(char *result, long int *nb)
{
	result[0] = '-';
	*nb = *nb * -1;
}

char	*ft_itoa(int n)
{
	int			count;
	char		*result;
	long int	nb;

	nb = n;
	count = ft_lenint(nb);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	if (nb < 0)
		add_minus(result, &nb);
	result[count--] = '\0';
	if (nb == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (nb > 0)
	{
		result[count--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (result);
}
