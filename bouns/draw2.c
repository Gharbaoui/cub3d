/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:34:26 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 16:49:42 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			draw_player_vew(t_player *pl)
{
	int			i;
	int			check;

	i = 0;
	check = draw_rays(pl, i);
	if (check)
	{
		ft_putstr("Error: problem while opening texture\n");
		exit(0);
	}
}

int				draw_rays(t_player *pl, int i)
{
	double		length;
	double		angel;
	int			width;
	double		toadd;

	width = pl->map.width;
	angel = pl->angel + 30;
	toadd = 60.0 / width;
	i = -1;
	if (open_images(pl))
		return (1);
	while (++i < width)
	{
		length = raycasting(pl, angel) * cos((pl->angel - angel) * M_PI / 180);
		draw_3world(length, pl, i, width);
		angel -= toadd;
	}
	return (0);
}

double			raycasting(t_player *pl, double angel)
{
	t_dir		dir;
	t_point		p;
	double		length_h;
	double		length_v;
	int			max;

	max = 2147483647;
	angel = handel_angel(angel);
	pl->hit = 0;
	handel_dirction(&dir, angel);
	first_step(&p, dir, pl, angel);
	length_h = (!dir.sleft && !dir.sright) ?
	horz_raycast(p, dir, pl, angel) : max;
	length_v = vert_raycast(dir, pl, angel);
	return (handel_raylength(length_h, length_v, pl));
}

double			horz_raycast(t_point p, t_dir dir, t_player *pl, double angel)
{
	t_point		hit;
	t_point		inp;
	int			hitcheck;

	inp.x = pl->pos.x + p.x;
	inp.y = p.y;
	dir.a = 0;
	angel = 0;
	while (is_in_screen(inp, pl->map.width, pl->map.height))
	{
		if ((hitcheck = is_there_wall(&(pl->map), inp.x, inp.y, &hit)) == 1 &&
		!(pl->wasvert = 0))
			break ;
		else if (hitcheck == 2 && pl->stop == 0)
			handel_sprite_new(&inp, pl, hit, dir);
		help_horz_raycast(&dir, &inp, &p, pl);
	}
	return (help_horz_ret(inp, &dir, pl, 0));
}
