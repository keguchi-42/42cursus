/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:25:51 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/05 02:59:18 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_free_free(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
}

void	all_free(t_info *info)
{
	ft_free((void *)info->sprites);
	ft_free((void *)info->z_buffer);
	ft_free_free((void **)info->map.worldmap);
	ft_free_free((void **)info->buf);
	ft_free((void *)info->map.name);
	ft_free((void *)info->map.path_n);
	ft_free((void *)info->map.path_s);
	ft_free((void *)info->map.path_w);
	ft_free((void *)info->map.path_e);
	ft_free((void *)info->map.path_sprite);
}
