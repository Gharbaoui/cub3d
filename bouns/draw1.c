/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:56:54 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 16:45:17 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			draw_one_line(t_player *pl, char *line)
{
	int			i;
	static int	check;

	i = -1;
	pl->help.x = 0;
	while (line[++i])
	{
		if (is_player_i(line[i]) && !check++)
			handel_player_info(pl, line[i]);
		pl->help.x += pl->map.squarewidth;
	}
	pl->help.y += pl->map.squareheight;
}

int				draw_world(t_player *pl)
{
	int		i;
	char	**line;

	i = -1;
	pl->help.y = 0;
	pl->help.x = 0;
	line = pl->map.maplines;
	pl->look = 0;
	while (line[++i])
		draw_one_line(pl, line[i]);
	return (4);
}

void			handel_player_info(t_player *pl, char c)
{
	if (c == 'N')
		pl->angel = 90;
	else if (c == 'W')
		pl->angel = 180;
	else if (c == 'E')
		pl->angel = 0;
	else
		pl->angel = 270;
	pl->pos.x = pl->help.x + (pl->map.squarewidth / 2);
	pl->pos.y = pl->help.y + (pl->map.squareheight / 2);
	draw_player_vew(pl);
}

void			help_horz_raycast(t_dir *dir, t_point *inp,
				t_point *p, t_player *pl)
{
	t_point		delta;

	delta.y = pl->map.squareheight;
	delta.y *= (dir->up || dir->sup) ? -1 : 1;
	p->y += delta.y;
	delta.x = !(dir->spec) ? delta.y / tan(dir->angel * M_PI / 180) : 0;
	delta.x *= (((dir->right || dir->sright) && delta.x < 0) ||
	((dir->sleft || dir->left) && delta.x > 0)) ? -1 : 1;
	p->x += delta.x;
	inp->x = pl->pos.x + p->x;
	inp->y = p->y;
}

double			help_horz_ret(t_point inp, t_dir *dir, t_player *pl, int a)
{
	int			max;

	max = 2147483647;
	if (a == 0)
	{
		inp.y += (dir->up || dir->sup) ? 1 : 0;
		if (!(pl->wasvert))
			pl->horz = inp;
		return (!(pl->wasvert) ? calculate_length(pl->pos.x, pl->pos.y,
		inp.x, inp.y) : max);
	}
	else
	{
		inp.x += (dir->left || dir->sleft) ? 1 : 0;
		if (pl->wasvert == 1)
			pl->vert = inp;
		return ((pl->wasvert) ? calculate_length(pl->pos.x, pl->pos.y,
		inp.x, inp.y) : max);
	}
	return (0);
}
