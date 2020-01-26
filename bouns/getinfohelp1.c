/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfohelp1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:38:07 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/23 22:43:27 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		rest_info(t_map_info *map, t_name_text *txt, int *i)
{
	txt->e = 0;
	txt->n = 0;
	txt->s = 0;
	txt->sp = 0;
	txt->w = 0;
	map->r = 0;
	txt->celling = -1;
	txt->floor = -1;
	*i = -1;
	return (0);
}

int		handel_rest_txt(char *line, char **str)
{
	return (handel_north(line, str));
}

int		handel_rest_of_txt(t_name_text *txt,
		t_map_info *map, int fd, char *line)
{
	while (get_next_line(fd, &line) && *line != '1')
	{
		(map->tofirstline)++;
		if ((map->err = help_rest1(txt, map, fd, line)))
			return (map->err);
		else if ((map->err = help_rest2(txt, map, fd, line)))
			return (map->err);
		else if (!str_cmp("F", line, 1) &&
		(map->err = help_get_color_map(line, txt, 1)))
			return (map->err);
		else if (!str_cmp("C", line, 1) &&
		(map->err = help_get_color_map(line, txt, 2)))
			return (map->err);
		if ((map->err = repeat_error(*txt, 0, map->r)))
			return (map->err);
		free(line);
	}
	return (short_help1(&(map->help), line));
}

int		repeat_error(t_name_text txt, int a, int r)
{
	if (a == 0)
	{
		if (txt.n > 1 || txt.s > 1 || txt.sp > 1 || txt.celling == -4)
			return (6);
		else if (txt.e > 1 || txt.w > 1 || txt.floor == -4 || r > 1)
			return (6);
	}
	else if (a == 1)
	{
		if (txt.n == 0 || txt.s == 0 || txt.sp == 0 || r == 0)
			return (5);
		else if (txt.e == 0 || txt.w == 0 ||
		txt.celling == -1 || txt.floor == -1)
			return (5);
	}
	return (0);
}
