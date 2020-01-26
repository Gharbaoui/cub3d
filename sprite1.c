/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:04:25 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/25 03:07:26 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		handel_sprite_new(t_point *hit, t_player *pl,
			t_point center, t_dir dir)
{
	double	angel;
	int		offset;
	double	angelsp;
	t_point	newp;
	t_point	sidepoint;

	small_help(dir.a, hit, dir);
	angel = handel_bet_ang(pl->pos, center, *hit, &angelsp);
	newp = handel_rotate_point(pl->pos, center, angel);
	sidepoint = handel_sidepoint(center, pl->radius, angelsp);
	offset = calculate_length(sidepoint.x, sidepoint.y, newp.x, newp.y);
	if (!is_inrange(newp, center, pl->radius))
		pl->hit = 0;
	else if (offset <= pl->radius * 2)
	{
		pl->hit = 1;
		pl->splength = calculate_length(pl->pos.x, pl->pos.y,
		center.x, center.y);
		pl->offset = (offset * pl->txtcolor.width[4]) / (pl->radius * 2);
		pl->stop = (pl->offset > pl->lr[0] && pl->offset < pl->lr[1]) ? 1 : 0;
		if (pl->stop == 0)
			pl->hit = 0;
	}
	else
		pl->hit = 0;
}
