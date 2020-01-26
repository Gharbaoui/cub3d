/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:05:36 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 15:18:13 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		rest_keys(t_keys *keys)
{
	keys->lookdown = 0;
	keys->lookup = 0;
	keys->left = 0;
	keys->right = 0;
	keys->up = 0;
	keys->down = 0;
}

char		*str_cat_txt(char *str, int *len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	while (str[i] != ' ' && str[i] != '\n' && str[i])
		i++;
	*len = i;
	tmp = malloc(i + 1);
	while (++j < i)
		tmp[j] = str[j];
	tmp[j] = '\0';
	return (tmp);
}

int			help_get_color_map(char *line, t_name_text *txt, int a)
{
	if (a == 1)
	{
		if (txt->floor != -1)
			txt->floor = -4;
		else if ((txt->floor = handel_rgb_int(&line[1], 0, 0)) < 0)
			return (txt->floor);
	}
	else if (a == 2)
	{
		if (txt->celling != -1)
			txt->celling = -4;
		else if ((txt->celling = handel_rgb_int(&line[1], 0, 0)) < 0)
			return (txt->celling);
	}
	return (0);
}

int			handel_rgb_int(char *str, int i, int check)
{
	int r;
	int g;
	int b;
	int len;

	help_short5(str, &i, 0, &check);
	if (help_short4(str, &len, &r, i))
		return (-9);
	i += len - 1;
	if (help_short3(str, &i, &check) || check == 0)
		return (-8);
	if (help_short4(str, &len, &g, i))
		return (-9);
	i += len - 1;
	if (help_short3(str, &i, &check) || check == 0)
		return (-8);
	if (help_short4(str, &len, &b, i))
		return (-9);
	if (r > 255 || b > 255 || g > 255)
		return (-10);
	i += len - 1;
	if (help_short5(str, &i, 1, &check) == -2)
		return (-2);
	return ((256 * 256) * r) + (256 * g) + b;
}

int			check_save(char *str)
{
	int	i;

	i = 5;
	if (!str_cmp("--save", str, 6))
	{
		while (str[++i])
			if (str[i] != ' ')
				return (0);
	}
	else
		return (0);
	return (1);
}
