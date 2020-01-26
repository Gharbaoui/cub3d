/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr9.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:59:53 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 16:02:02 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				is_valid_name(char *str)
{
	int			lastindex;

	lastindex = ft_strlen(str) - 1;
	if (str[lastindex] == 'b' && str[lastindex - 1] == 'u'
	&& str[lastindex - 2] == 'c')
		return (1);
	return (0);
}

void			*ft_memcpy(void *dest, const void *sourc, size_t size)
{
	char		*dst;
	char		*src;

	dst = dest;
	src = (char *)sourc;
	if (!dst && !src)
		return (0);
	if (dst == src)
		return (dst);
	while (size)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	return (dest);
}

void			*my_calloc(int a, int b)
{
	char		*tmp;
	int			size;
	int			i;

	i = -1;
	size = a * b;
	if (!(tmp = malloc(size)))
		return (tmp);
	while (++i < size)
		tmp[i] = '\0';
	return (tmp);
}

int				get_color(int y, int x, void *img_ptr, int width)
{
	int			k;
	int			*data;
	int			color;

	data = (int *)mlx_get_data_addr(img_ptr, &k, &k, &k);
	color = data[y * width + x];
	return (color);
}
