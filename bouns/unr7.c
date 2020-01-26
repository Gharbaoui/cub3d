/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:07:12 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/25 02:11:04 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			help_fill_map(t_player *pl)
{
	if (!(pl->txtcolor.img = malloc(sizeof(int *) * 5)))
		return (-21);
	if (!(pl->txtcolor.width = malloc(sizeof(int) * 5)))
	{
		free(pl->txtcolor.img);
		return (-21);
	}
	if (!(pl->txtcolor.height = malloc(sizeof(int) * 5)))
	{
		free(pl->txtcolor.img);
		free(pl->txtcolor.width);
		return (-21);
	}
	if (handel_sp_bounds(pl))
		return (1);
	pl->radius = (pl->map.squareheight > pl->map.squarewidth) ?
	pl->map.squarewidth : pl->map.squareheight;
	pl->radius /= 2;
	pl->divid = pl->map.height / 8;
	return (0);
}

int			handel_sp_bounds(t_player *pl)
{
	int		i;
	int		fd;
	int		numlines;
	int		numcolors;
	char	*line;

	i = -1;
	fd = open(pl->txt.sprite, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error: while opening sprite\n");
		exit(0);
	}
	while (++i < 3 && get_next_line(fd, &line))
		free(line);
	get_next_line(fd, &line);
	handel_numbers(&numlines, &numcolors, line);
	free(line);
	i = -1;
	while (++i < numcolors + 1 && get_next_line(fd, &line))
		free(line);
	handel_lr(&(pl->lr[0]), fd, numlines, &(pl->lr[1]));
	return (0);
}

void		handel_numbers(int *numlines, int *numcolors, char *line)
{
	int		i;
	int		len;

	i = 0;
	line++;
	ft_atoi(line, &len);
	line += len;
	while (line[i] == ' ')
		i++;
	*numlines = ft_atoi(&line[i], &len);
	line += len + i;
	i = 0;
	while (line[i] == ' ')
		i++;
	*numcolors = ft_atoi(&line[i], &len);
}

void		handel_lr(int *num, int fd, int numlines, int *right)
{
	int		lcount;
	int		rcount;
	int		length;
	int		i;
	char	*line;

	i = -1;
	get_next_line(fd, &line);
	*right = 0;
	length = ft_strlen(line) - 3;
	*num = length - 1;
	while (++i < numlines)
	{
		handel_one_line_lr(&line[1], &lcount, &rcount, length);
		if (lcount < *num)
			*num = lcount;
		if (rcount > *right)
			*right = rcount;
		free(line);
		get_next_line(fd, &line);
	}
	*num -= 1;
	free(line);
}

void		handel_one_line_lr(char *line, int *lcount, int *rcount, int length)
{
	int i;

	i = -1;
	*lcount = 0;
	*rcount = length;
	while (line[++i])
	{
		if (line[i] == ' ')
			(*lcount)++;
		else
			break ;
	}
	i = *rcount;
	while (line[--i])
	{
		if (line[i] == ' ')
			(*rcount)--;
		else
			break ;
	}
}
