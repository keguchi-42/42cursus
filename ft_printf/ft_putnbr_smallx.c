/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_smallx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:49:29 by keguchi           #+#    #+#             */
/*   Updated: 2020/10/08 22:25:06 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numlen_x(unsigned long num)
{
	int		count;

	count = 0;
	while (num >= 16)
	{
		count++;
		num /= 16;
	}
	return (count + 1);
}

void	ft_putoutnbr_x(unsigned long num, int sign, int precision)
{
	char c;

	if (sign == -1)
		ft_putchar('-');
	if (precision != -1)
		ft_putzero(precision);
	if (num >= 16)
		ft_putoutnbr_x(num / 16, 1, -1);
	if (num % 16 < 10)
	{
		c = num % 16 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = num % 16 + '0' + 39;
		write(1, &c, 1);
	}
}

void	ft_putnumpre_x(unsigned int num, t_flags *elements, int count)
{
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	width = MAX(elements->width, count);
	precision = elements->precision;
	precision -= count;
	if (precision < 0)
		precision = 0;
	if (elements->minus)
	{
		ft_putoutnbr_x(num, elements->sign, precision);
		ft_putspace(width - precision - count + elements->sign);
	}
	else
	{
		ft_putspace(width - precision - count + elements->sign);
		ft_putoutnbr_x(num, elements->sign, precision);
	}
}

void	ft_putnumnopre_x(unsigned int num, t_flags *elements, int count)
{
	int		width;

	width = 0;
	width = MAX(elements->width, count);
	if (elements->minus)
	{
		ft_putoutnbr_x(num, elements->sign, -1);
		ft_putspace(width - count + elements->sign);
	}
	else if (elements->zero)
	{
		if (elements->sign == -1)
			ft_putchar('-');
		ft_putzero(width - count + elements->sign);
		ft_putoutnbr_x(num, 1, -1);
	}
	else
	{
		ft_putspace(width - count + elements->sign);
		ft_putoutnbr_x(num, elements->sign, -1);
	}
}

int		ft_putnbr_smallx(unsigned int nb, t_flags *elements)
{
	unsigned int	num;
	int				count;

	num = nb;
	count = 0;
	if (num == 0 && elements->precision == 0)
	{
		ft_putspace(elements->width);
		return (elements->width);
	}
	count = ft_numlen_x(num);
	if (elements->precision != -1)
		ft_putnumpre_x(num, elements, count);
	else
		ft_putnumnopre_x(num, elements, count);
	if (elements->sign == -1)
	{
		count += 1;
		elements->precision += 1;
	}
	return (MAX(elements->precision, MAX(count, elements->width)));
}
