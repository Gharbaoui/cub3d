/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:06:28 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 17:01:10 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			can_move(t_player *pl, char c, double speed, t_point *newp)
{
	double	x;
	double	y;
	t_point	p;

	x = 0;
	y = 0;
	if (c == 'U')
	{
		x = pl->pos.x + (cos(pl->angel * M_PI / 180) * speed);
		y = pl->pos.y - (sin(pl->angel * M_PI / 180) * speed);
	}
	else if (c == 'D')
	{
		x = pl->pos.x - (cos(pl->angel * M_PI / 180) * speed);
		y = pl->pos.y + (sin(pl->angel * M_PI / 180) * speed);
	}
	p.x = x;
	p.y = y;
	if (!is_there_wall(&(pl->map), x, y, newp))
	{
		*newp = p;
		return (1);
	}
	return (0);
}
