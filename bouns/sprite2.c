/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:38:42 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/25 02:43:27 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		small_help(int h, t_point *p, t_dir dir)
{
	if (h == 0)
		p->y += (dir.up || dir.sup) ? 1 : 0;
	else if (h == 1)
		p->x += (dir.left || dir.sleft) ? 1 : 0;
	else if (h == 2)
		p->y -= (dir.up || dir.sup) ? 1 : 0;
	else if (h == 3)
		p->x -= (dir.left || dir.sleft) ? 1 : 0;
}

double		handel_bet_ang(t_point p1, t_point p2, t_point p3, double *angel)
{
	double	angel1;
	double	angel2;

	angel1 = atan2(p2.y - p1.y, p2.x - p1.x);
	*angel = angel1;
	angel2 = atan2(p3.y - p1.y, p3.x - p1.x);
	return (angel1 - angel2);
}

t_point		handel_rotate_point(t_point on, t_point to, double angel)
{
	t_point	toorigin;
	t_point	rotonorigin;
	t_point p;

	toorigin.x = to.x - on.x;
	toorigin.y = to.y - on.y;
	rotonorigin.x = (toorigin.x * cos(angel) + (toorigin.y * sin(angel)));
	rotonorigin.y = ((toorigin.y * cos(angel)) - (toorigin.x * sin(angel)));
	p.x = rotonorigin.x + on.x;
	p.y = rotonorigin.y + on.y;
	return (p);
}

t_point		handel_sidepoint(t_point center, double radius, double angel)
{
	t_point	p;

	p.x = center.x + (sin(angel) * radius);
	p.y = center.y - (cos(angel) * radius);
	return (p);
}

int			is_inrange(t_point newp, t_point center, double radius)
{
	double	length;

	length = calculate_length(newp.x, newp.y, center.x, center.y);
	if (length <= radius)
		return (1);
	return (0);
}
