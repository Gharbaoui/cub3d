/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:29:33 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/25 04:47:41 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			handel_map_lines(t_map_info *map, int fd, int cnum)
{
	int		err;
	int		check;
	char	*line;
	int		lines;
	int		lastcnum;

	check = 0;
	if ((lines = 1) &&
	!(err = 0) &&
	((lastcnum = handel_line_per_line(map->help, 0)) < 0))
		return (lastcnum);
	while (get_next_line(fd, &line) || (++check && *line == '1'))
	{
		if (((cnum = handel_line_per_line(line, 1)) < 0 ||
		((err = cnum - lastcnum) && cnum != 0)))
			return ((err != 0) ? -14 : cnum);
		else if (cnum > 0)
			lines++;
		free(line);
	}
	free(line);
	if (check != 2)
		return (-18);
	map->map_lines = lines;
	return (lastcnum);
}

int			handel_line_per_line(char *line, int a)
{
	int		i;
	int		check;
	int		counter;
	char	pervchar;

	if (help_short1(line, &counter, &i))
		return (0);
	if (line[0] != '1')
		return (-11);
	while (line[++i])
	{
		if ((check = is_one_of_map(line[i])))
		{
			if (check == 1 && ++counter)
				pervchar = line[i];
			if (a == 0 && pervchar != '1')
				return (-15);
		}
		else
			return (-12);
	}
	if (pervchar != '1')
		return (-13);
	return (counter);
}

int			is_one_of_map(char c)
{
	if (c == '1' || c == '2' || c == 'W' || c == '0')
		return (1);
	else if (c == 'N' || c == 'E' || c == 'S')
		return (1);
	else if (c == ' ')
		return (2);
	return (0);
}

int			help_short1(char *line, int *counter, int *i1)
{
	int i;

	i = 0;
	*i1 = -1;
	*counter = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int			is_player_i(char c)
{
	return ((c == 'N' || c == 'E' || c == 'S' || c == 'W') ? 1 : 0);
}
