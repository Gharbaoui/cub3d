/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:02:36 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 21:03:16 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		clear(t_player **ptr)
{
	mlx_destroy_image((*ptr)->acc.mlx_ptr, (*ptr)->acc.img_ptr);
	mlx_clear_window((*ptr)->acc.mlx_ptr, (*ptr)->acc.win_ptr);
	(*ptr)->acc.img_ptr = mlx_new_image((*ptr)->acc.mlx_ptr,\
	(*ptr)->map.width, (*ptr)->map.height);
}

int			key_press(int key, t_player *pl)
{
	if (key == 2 || key == 124)
		pl->keys->right = 1;
	else if (key == 0 || key == 123)
		pl->keys->left = 1;
	else if (key == 13)
		pl->keys->up = 1;
	else if (key == 1)
		pl->keys->down = 1;
	else if (key == 126)
		pl->keys->lookup = 1;
	else if (key == 125)
		pl->keys->lookdown = 1;
	else if (key == 53)
	{
		clear(&pl);
		exit(0);
	}
	return (0);
}

int			key_rel(int key, t_keys *keys)
{
	if (key == 2 || key == 124)
		keys->right = -1;
	else if (key == 0 || key == 123)
		keys->left = -1;
	else if (key == 13)
		keys->up = -1;
	else if (key == 1)
		keys->down = -1;
	else if (key == 126)
		keys->lookup = -1;
	else if (key == 125)
		keys->lookdown = -1;
	return (0);
}

int			goout(int key)
{
	(void)key;
	exit(0);
}

int			key_move(t_player *pl)
{
	t_point	newp;
	double	speed;

	speed = 25;
	mlx_hook(pl->acc.win_ptr, 2, 0, key_press, pl);
	mlx_hook(pl->acc.win_ptr, 3, 0, key_rel, (pl->keys));
	mlx_hook(pl->acc.win_ptr, 17, 0, goout, 0);
	if (pl->keys->right == 1)
		pl->angel -= 10;
	if (pl->keys->left == 1)
		pl->angel += 10;
	if (pl->keys->up == 1 && (can_move(pl, 'U', speed, &newp)))
		pl->pos = newp;
	if (pl->keys->down == 1 && (can_move(pl, 'D', speed, &newp)))
		pl->pos = newp;
	if (pl->keys->lookdown == 1 && (pl->look >= -150))
		pl->look -= 8;
	else if (pl->keys->lookup == 1 && (pl->look <= 150))
		pl->look += 8;
	clear(&pl);
	draw_player_vew(pl);
	mlx_put_image_to_window(pl->acc.mlx_ptr, pl->acc.win_ptr,
	pl->acc.img_ptr, 0, 0);
	return (0);
}
