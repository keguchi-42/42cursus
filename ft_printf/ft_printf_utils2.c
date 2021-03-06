/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 05:23:39 by keguchi           #+#    #+#             */
/*   Updated: 2020/10/08 15:01:15 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_check_sign(unsigned long num, t_flags *elements)
{
	elements->sign = -1;
	num = num * -1;
	return (num);
}

void			ft_struct_init(t_flags *elements)
{
	elements->zero = 0;
	elements->minus = 0;
	elements->width = 0;
	elements->precision = -1;
	elements->preswitch = 0;
	elements->sign = 0;
}

void			ft_put0x(void)
{
	ft_putchar('0');
	ft_putchar('x');
}
