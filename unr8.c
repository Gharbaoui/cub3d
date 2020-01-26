/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:31:46 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/23 22:32:59 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		fill_void_data(t_player *pl)
{
	pl->acc.mlx_ptr = mlx_init();
	if (!pl->acc.mlx_ptr)
		return (-22);
	pl->acc.win_ptr = mlx_new_window(pl->acc.mlx_ptr,
	pl->map.width, pl->map.height, "CUB");
	pl->acc.img_ptr = mlx_new_image(pl->acc.mlx_ptr,
	pl->map.width, pl->map.height);
	if (!pl->acc.win_ptr || !pl->acc.img_ptr)
		return (-22);
	return (0);
}
