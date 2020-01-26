/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:05:25 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/23 22:07:02 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			fill_map_lines(char *mapname, t_map_info *map)
{
	int		i;
	int		fd;
	char	*line;

	map->maplines = malloc(sizeof(char *) * (map->map_lines + 1));
	if (!(map->maplines))
		return (-21);
	if ((fd = open(mapname, O_RDONLY)) == -1)
		return (-1);
	i = -1;
	while (++i < map->tofirstline && get_next_line(fd, &line))
		free(line);
	i = -1;
	while (++i < map->map_lines)
	{
		get_next_line(fd, &line);
		if (!(map->maplines[i] = line_no_space(line, map->c)))
			return (-21);
		free(line);
	}
	map->maplines[i] = NULL;
	return (0);
}

char		*line_no_space(char *line, int length)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!(ptr = malloc(sizeof(char) * (length + 1))))
		return (ptr);
	while (line[++i])
		if (line[i] != ' ')
			ptr[++j] = line[i];
	ptr[++j] = '\0';
	return (ptr);
}

int			last_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			return (1);
	return (0);
}

int			player_repeat(char **str, int *numsp)
{
	int		i;
	int		objnum;
	int		objnum1;
	int		hp;
	int		pl;

	i = -1;
	pl = 0;
	objnum1 = 0;
	while (str[++i])
	{
		if ((hp = is_player(str[i], &objnum)))
			pl += hp;
		objnum1 += objnum;
	}
	if (pl != 1)
		return (-19);
	*numsp = objnum1;
	return (0);
}
