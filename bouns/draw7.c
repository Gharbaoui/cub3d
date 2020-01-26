/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:49:02 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 16:55:05 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		put_pixel(t_player pl, int x, int y, int color)
{
	int		*data;
	int		k;
	int		width;

	width = pl.map.width;
	data = (int *)mlx_get_data_addr(pl.acc.img_ptr, &k, &k, &k);
	if (y == pl.map.height)
		y--;
	data[x + (width * y)] = color;
}

int			sprite_color(t_player *pl, int i, double height)
{
	int		yindex;
	int		xindex;

	yindex = (i * pl->txtcolor.height[4]) / height;
	xindex = pl->offset;
	return (pl->txtcolor.img[4][xindex + (yindex * pl->txtcolor.width[4])]);
}

void		draw_sprite(t_player *pl, int x, int i, double y1)
{
	double	spheight;
	double	height;
	double	tmpheight;
	double	toproj;
	int		color;

	i = 0;
	spheight = (pl->map.height / 20);
	toproj = (pl->map.width / 2) / tan(30 * M_PI / 180);
	height = (spheight * toproj) / pl->splength;
	y1 = ((pl->map.height - height) / 2) + pl->look;
	tmpheight = height;
	if (y1 < 0 && (height = pl->map.height))
	{
		i = (-1 * y1);
		y1 = 0;
	}
	while (height-- > 0 && i <= tmpheight && y1 <= pl->map.height)
	{
		color = sprite_color(pl, i, tmpheight);
		if (color != 0)
			put_pixel(*pl, x, y1, color);
		y1++;
		i++;
	}
}
