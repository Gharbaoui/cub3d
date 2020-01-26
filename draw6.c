/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:25:32 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 17:06:43 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		draw_3world(double length, t_player *pl, int x, int d)
{
	double	height;
	double	tmpheight;
	double	y;
	int		itxt;
	int		color;

	pl->i = -1;
	color = pl->txt.celling;
	d = pl->divid;
	pl->length = length;
	pl->angel = handel_angel(pl->angel);
	height = virtual_height(pl, &y, &itxt, &tmpheight);
	while (++(pl->i) < y)
		put_pixel(*pl, x, (pl->i), color);
	height++;
	y = (int)y;
	while (--height > 0 && y <= pl->map.height && itxt <= tmpheight)
	{
		color = txt_color(pl, x, itxt, tmpheight);
		color = tran(color, length, d);
		itxt++;
		put_pixel(*pl, x, y, color);
		y++;
	}
	help_draw_world(y - 1, pl, length, x);
}

double		virtual_height(t_player *pl, double *y, int *i, double *tmpheight)
{
	double	toproj;
	double	wallheight;
	double	vheight;
	double	y1;

	*i = 0;
	wallheight = (pl->map.height / 20);
	toproj = (pl->map.width / 2) / tan(30 * M_PI / 180);
	vheight = (wallheight * toproj) / pl->length;
	y1 = (pl->map.height - vheight) / 2;
	*tmpheight = vheight;
	y1 += pl->look;
	if (y1 < 0)
	{
		vheight = pl->map.height;
		(*i) = (-1 * y1);
		y1 = 0;
	}
	*y = (int)y1;
	return (vheight);
}

int			txt_color(t_player *pl, int x, int itxt, double height)
{
	int	xindex;
	int	yindex;
	int	wy;
	int	wx;
	int	i;

	x = 0;
	if (pl->wasvert)
	{
		i = (pl->vert.x > pl->pos.x) ? 1 : 2;
		wy = ((int)pl->vert.y % pl->map.squareheight);
		xindex = (wy * pl->txtcolor.width[i]) / pl->map.squareheight;
	}
	else
	{
		i = (pl->vert.y > pl->pos.y) ? 0 : 3;
		wx = ((int)pl->vert.x % pl->map.squarewidth);
		xindex = (wx * pl->txtcolor.width[i]) / pl->map.squarewidth;
	}
	yindex = (itxt * pl->txtcolor.height[i]) / height;
	return (pl->txtcolor.img[i][xindex + (yindex * pl->txtcolor.width[i])]);
}

int			tran(int color, double length, int d)
{
	int		r;
	int		color1;
	double	mult;
	int		g;
	int		b;

	r = color / pow(256, 2);
	g = (color / 256) % 256;
	b = color % 256;
	if ((mult = length / d) > 1)
	{
		r = r / mult;
		b = b / mult;
		g = g / mult;
	}
	else
		return (color);
	color1 = (r * pow(256, 2)) + (g * 256) + b;
	return (color1);
}

void		help_draw_world(int i, t_player *pl, double length, int x)
{
	int		color;
	int		a;
	double	y;

	a = 0;
	y = 0;
	color = pl->txt.floor;
	while (++i < pl->map.height)
		put_pixel(*pl, x, i, color);
	if (pl->hit && pl->splength < length)
		draw_sprite(pl, x, a, y);
}
