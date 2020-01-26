/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:23:11 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 20:58:29 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		help_rest1(t_name_text *txt, t_map_info *map, int fd, char *line)
{
	fd = 0;
	if (!str_cmp("R", line, 1) && ++(map->r) == 1 &&
	(map->err = helpresolution(map, line)))
	{
		return (map->err);
	}
	else if (!str_cmp("NO", line, 2) && (++(txt->n) == 1) &&
	(map->err = handel_rest_txt(&line[2], &(txt->north))))
	{
		return (map->err);
	}
	else if (!str_cmp("SO", line, 2) && (++(txt->s) == 1) &&
	(map->err = handel_rest_txt(&line[2], &(txt->south))))
	{
		return (map->err);
	}
	return (0);
}

int		help_rest2(t_name_text *txt, t_map_info *map, int fd, char *line)
{
	fd = 0;
	if (!str_cmp("WE", line, 2) && (++(txt->w) == 1) &&
	(map->err = handel_rest_txt(&line[2], &(txt->weast))))
	{
		return (map->err);
	}
	else if (!str_cmp("EA", line, 2) && ++(txt->e) == 1 &&
	(map->err = handel_rest_txt(&line[2], &(txt->east))))
	{
		return (map->err);
	}
	else if (!str_cmp("S", line, 1) && str_cmp("SO", line, 2) &&
	++(txt->sp) == 1 && (map->err = handel_rest_txt(&line[1], &(txt->sprite))))
	{
		return (map->err);
	}
	return (0);
}

void	help_err(int check)
{
	if (check == 1 || check == -1)
		ft_putstr("Error: Something went wrong with some file\n");
	else if (check == 2 || check == -2)
		ft_putstr("Error: Somthing should't be there\n");
	else if (check == 3)
		ft_putstr("Error: there's more than tow number's\n");
	else if (check == 4)
		ft_putstr("Error: not enough information\n");
	else if (check == 5)
		ft_putstr("Error: not found\n");
	else if (check == 6)
		ft_putstr("Error: repeat one\n");
	else if (check == -10)
		ft_putstr("Error: Not A valid a color\n");
	else if (check == -9)
		ft_putstr("Error: not enough number's in rgb color\n");
	else if (check == -8)
		ft_putstr("Error: There's no ',' in color\n");
	else if (check == -11)
		ft_putstr("Error: your map is open from the left\n");
	else if (check == -22)
		ft_putstr("Error: problem with some mlx func\n");
}

int		handel_resol_error(int check)
{
	help_err(check);
	if (check == -12)
		ft_putstr("Error: somthing else in the map should't be there\n");
	else if (check == -13)
		ft_putstr("Error: your map is open from the right\n");
	else if (check == -14)
		ft_putstr("Error: different lines in map\n");
	else if (check == -15)
		ft_putstr("Error: your map is open from the middel\n");
	else if (check == -16)
		ft_putstr("Error: last line of the map is open\n");
	else if (check == -17)
		ft_putstr("Error: empty line in map\n");
	else if (check == -18)
		ft_putstr("Error: empty lines at the end of the map\n");
	else if (check == -19)
		ft_putstr("Error: probelm with player\n");
	else if (check == -20)
		ft_putstr("Error: not valid R\n");
	else if (check == -21)
		ft_putstr("Error: problem with malloc\n");
	else if (check == -29)
		ft_putstr("Error: Something went wrong with arg\n");
	exit(0);
	return (1);
}

void	handel_width(t_map_info *map)
{
	if (map->width > 2560)
		map->width = 2560;
	if (map->height > 1440)
		map->height = 1440;
	map->squarewidth = (map->width / map->c);
	map->squareheight = (map->height / map->map_lines);
}
