/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:34:24 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 16:58:37 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			fill_map_info(t_player *pl, char *mapname)
{
	int		numsp;
	int		check;

	check = handel_txt(&(pl->txt), mapname, &(pl->map));
	if (check)
		return (handel_resol_error(check));
	handel_width(&(pl->map));
	check = player_repeat(pl->map.maplines, &numsp);
	if (check)
		return (handel_resol_error(check));
	if ((check = help_fill_map(pl)))
		return (check);
	return (0);
}

int			handel_txt(t_name_text *txt, char *mapname, t_map_info *map)
{
	int		i;
	int		fd;
	int		err;
	char	*line;
	int		cnum;

	map->tofirstline = 0;
	cnum = 0;
	line = NULL;
	if ((fd = open(mapname, O_RDONLY)) == -1 || rest_info(map, txt, &i))
		return (1);
	if ((err = handel_rest_of_txt(txt, map, fd, line)))
		return (err);
	if ((err = repeat_error(*txt, 1, map->r)))
		return (err);
	map->c = handel_map_lines(map, fd, cnum);
	if (map->width == 0 || map->height == 0)
		return (-20);
	if (map->c < 0)
		return (map->c);
	if ((err = fill_map_lines(mapname, map)) < 0)
		return (err);
	if (last_line(map->maplines[map->map_lines - 1]))
		return (-16);
	return (0);
}

int			handel_north(char *line, char **str)
{
	int		i;
	int		len;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i] == 0)
		return (4);
	*str = str_cat_txt(&line[i], &len);
	len += i - 1;
	while (line[++len])
		if (line[len] != ' ')
			return (2);
	return (0);
}
