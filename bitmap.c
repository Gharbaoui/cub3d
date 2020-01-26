/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:47:38 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 16:47:28 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int						handel_size_in_bytes(int width, int height, int *w)
{
	int					padding;
	int					bitcount;
	int					width_in_bytes;

	bitcount = 24;
	padding = ((4 - ((width * 3) % 4)));
	padding = (padding == 4) ? 0 : padding;
	padding *= 8;
	width_in_bytes = ((width * bitcount) + padding) / 8;
	*w = width_in_bytes;
	return (width_in_bytes * height);
}

void					help_bitmap(t_player pl, char **header, int *all)
{
	all[1] = 54 + all[0];
	all[2] = 54;
	all[3] = 40;
	all[4] = 1;
	all[5] = 24;
	ft_memcpy(*header, "BM", 2);
	ft_memcpy(*header + 2, &all[1], 4);
	ft_memcpy(*header + 10, &all[2], 4);
	ft_memcpy(*header + 14, &all[3], 4);
	ft_memcpy(*header + 18, &pl.map.width, 4);
	ft_memcpy(*header + 22, &pl.map.height, 4);
	ft_memcpy(*header + 26, &all[4], 2);
	ft_memcpy(*header + 28, &all[5], 2);
	ft_memcpy(*header + 34, &all[0], 4);
}

int						my_bitmap(t_player pl)
{
	int					all[10];
	int					fd;
	int					width_in_bytes;
	unsigned char		*buf;
	char				*header;

	all[0] = handel_size_in_bytes(pl.map.width, pl.map.height, &width_in_bytes);
	if (!(header = my_calloc(1, 54)))
		return (1);
	help_bitmap(pl, &header, all);
	if (!(buf = malloc(all[0])))
		return (1);
	test(pl, &buf, width_in_bytes, 0);
	fd = open("test.bmp", O_RDWR | O_CREAT, 777);
	write(fd, header, 54);
	write(fd, buf, all[0]);
	free(buf);
	return (0);
}

int						tran_color(int color, int r, int g, int b)
{
	if (r == 1)
		return (color / pow(256, 2));
	else if (g == 1)
		return ((color / 256) % 256);
	else if (b == 1)
		return (color % 256);
	return (0);
}

void					test(t_player pl, unsigned char **buf1,
						int width_in_bytes, int color)
{
	int					row;
	int					col;
	int					j;
	int					i;

	row = -1;
	j = pl.map.height;
	while (++row < pl.map.height)
	{
		--j;
		col = -1;
		i = -1;
		while (++col < pl.map.width)
		{
			++i;
			color = get_color(j, i, pl.acc.img_ptr, pl.map.width);
			(*buf1)[row * width_in_bytes + col * 3] =
			tran_color(color, 0, 0, 1);
			(*buf1)[row * width_in_bytes + col * 3 + 1] =
			tran_color(color, 0, 1, 0);
			(*buf1)[row * width_in_bytes + col * 3 + 2] =
			tran_color(color, 1, 0, 0);
		}
	}
}
