/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:44:23 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/25 01:51:31 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double		handel_angel(double angel)
{
	int		ang;
	double	reangel;
	double	smalltip;

	ang = (int)angel;
	smalltip = angel - (double)ang;
	ang = (ang + 360) % 360;
	reangel = (double)ang + smalltip;
	if (reangel < 0)
		reangel += 360;
	return (reangel);
}

void		handel_dirction(t_dir *dir, double angel)
{
	rest_dir_info(dir);
	if (angel == 0)
		dir->sright = 1;
	else if (angel == 180)
		dir->sleft = 1;
	else if (angel == 90)
		dir->sup = 1;
	else if (angel == 270)
		dir->sdown = 1;
	else
	{
		if (angel > 0 && angel < 180)
			dir->up = 1;
		else if (angel > 180 && angel < 360)
			dir->down = 1;
		if ((angel > 270 && angel <= 360) || (angel >= 0 && angel < 90))
			dir->right = 1;
		else if ((angel > 90 && angel < 270))
			dir->left = 1;
		dir->spec = 0;
	}
	dir->angel = angel;
}

void		rest_dir_info(t_dir *dir)
{
	dir->up = 0;
	dir->down = 0;
	dir->left = 0;
	dir->right = 0;
	dir->spec = 1;
	dir->sleft = 0;
	dir->sright = 0;
	dir->sup = 0;
	dir->sdown = 0;
}

void		first_step(t_point *p, t_dir dir, t_player *pl, double angel)
{
	p->y = (int)pl->pos.y - ((int)pl->pos.y % pl->map.squareheight);
	p->y += (dir.down || dir.sdown) ? pl->map.squareheight : 0;
	p->x = (!dir.spec) ? (pl->pos.y - p->y) / tan(angel * M_PI / 180) : 0;
	p->x *= (dir.right && p->x < 0) ? -1 : 1;
	p->x *= (dir.left && p->x > 0) ? -1 : 1;
	p->y -= (dir.up || dir.sup) ? 1 : 0;
	pl->wasvert = 1;
	pl->stop = 0;
}

double		calculate_length(double x1, double y1, double x2, double y2)
{
	double	length;
	double	dx;
	double	dy;

	dx = ((x2 - x1) * (x2 - x1));
	dy = ((y1 - y2) * (y1 - y2));
	length = sqrt(dx + dy);
	return (length);
}
