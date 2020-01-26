/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:37:42 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 17:13:57 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				main(int argc, char **argv)
{
	t_player	pl;
	int			check;

	if (!(pl.keys = malloc(sizeof(t_keys))))
		exit(0);
	rest_keys((pl.keys));
	if (argc > 1 && argc < 4 && is_valid_name(argv[1]))
	{
		if ((check = fill_map_info(&pl, argv[1])))
			return (handel_resol_error(check));
	}
	else
		return (handel_resol_error(-29));
	if ((check = fill_void_data(&pl)))
		return (handel_resol_error(check));
	draw_world(&pl);
	mlx_put_image_to_window(pl.acc.mlx_ptr, pl.acc.win_ptr,
	pl.acc.img_ptr, 0, 0);
	if (argc > 2 && check_save(argv[2]) && my_bitmap(pl))
		return (handel_resol_error(-21));
	else if (argc > 2)
		return (handel_resol_error(-29));
	mlx_loop_hook(pl.acc.mlx_ptr, key_move, &pl);
	mlx_loop(pl.acc.mlx_ptr);
}
