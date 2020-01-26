/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:02:39 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 16:50:12 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			open_images(t_player *pl)
{
	void	*txt;
	int		k;
	int		*tap4;
	int		*tap5;

	if (help_open_img(pl))
		return (1);
	txt = mlx_xpm_file_to_image(pl->acc.mlx_ptr, pl->txt.east,
	&(pl->txtcolor.width[1]), &(pl->txtcolor.height[1]));
	if (!txt)
		return (1);
	tap4 = (int *)mlx_get_data_addr(txt, &k, &k, &k);
	pl->txtcolor.img[1] = tap4;
	txt = mlx_xpm_file_to_image(pl->acc.mlx_ptr, pl->txt.sprite,
	&(pl->txtcolor.width[4]), &(pl->txtcolor.height[4]));
	if (!txt)
		return (1);
	tap5 = (int *)mlx_get_data_addr(txt, &k, &k, &k);
	pl->txtcolor.img[4] = tap5;
	return (0);
}

int			help_open_img(t_player *pl)
{
	void	*txt;
	int		*tap1;
	int		*tap2;
	int		*tap3;
	int		k;

	txt = mlx_xpm_file_to_image(pl->acc.mlx_ptr, pl->txt.north,
	&(pl->txtcolor.width[3]), &(pl->txtcolor.height[3]));
	if (!txt)
		return (1);
	tap1 = (int *)mlx_get_data_addr(txt, &k, &k, &k);
	pl->txtcolor.img[3] = tap1;
	txt = mlx_xpm_file_to_image(pl->acc.mlx_ptr, pl->txt.south,
	&(pl->txtcolor.width[0]), &(pl->txtcolor.height[0]));
	if (!txt)
		return (1);
	tap2 = (int *)mlx_get_data_addr(txt, &k, &k, &k);
	pl->txtcolor.img[0] = tap2;
	txt = mlx_xpm_file_to_image(pl->acc.mlx_ptr, pl->txt.weast,
	&(pl->txtcolor.width[2]), &(pl->txtcolor.height[2]));
	if (!txt)
		return (1);
	tap3 = (int *)mlx_get_data_addr(txt, &k, &k, &k);
	pl->txtcolor.img[2] = tap3;
	return (0);
}

int			is_in_screen(t_point p, double width, double heigth)
{
	if ((p.x > 0 && p.x < width) && (p.y > 0 && p.y < heigth))
		return (1);
	return (0);
}

int			is_there_wall(t_map_info *map, double x, double y, t_point *hitpos)
{
	int		xindex;
	int		yindex;

	xindex = (int)(x / map->squarewidth);
	yindex = (int)(y / map->squareheight);
	if (yindex == map->map_lines)
		yindex--;
	if (xindex == map->c)
		xindex--;
	if (map->maplines[yindex][xindex] == '1')
		return (1);
	if (map->maplines[yindex][xindex] == '2')
	{
		hitpos->x = (xindex * map->squarewidth) + (map->squarewidth / 2);
		hitpos->y = (yindex * map->squareheight) + (map->squareheight / 2);
		return (2);
	}
	return (0);
}
