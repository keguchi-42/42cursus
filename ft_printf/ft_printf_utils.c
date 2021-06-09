/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 18:09:10 by keguchi           #+#    #+#             */
/*   Updated: 2020/10/04 17:44:22 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putspace(int i)
{
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void	ft_putzero(int i)
{
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

void	ft_putstr(char *str, int count)
{
	int i;

	i = 0;
	while (count > i)
	{
		ft_putchar(str[i]);
		i++;
	}
}
