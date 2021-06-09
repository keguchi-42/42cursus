/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:46:23 by keguchi           #+#    #+#             */
/*   Updated: 2020/10/08 06:44:01 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc(int i, t_flags *elements)
{
	int		count;

	count = 0;
	count = elements->width;
	if (elements->width == 0)
	{
		count = 1;
		ft_putchar(i);
	}
	else if (elements->minus)
	{
		ft_putchar(i);
		ft_putspace(count - 1);
	}
	else if (elements->zero)
	{
		ft_putzero(count - 1);
		ft_putchar(i);
	}
	else
	{
		ft_putspace(count - 1);
		ft_putchar(i);
	}
	return (count);
}
