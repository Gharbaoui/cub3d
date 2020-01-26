/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfohelp3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:44:51 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/23 22:58:09 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		help_var(int *i, int *done, int *check, int *len)
{
	*i = 0;
	*done = 0;
	*len = 0;
	*check = 0;
}

int			helpresolution(t_map_info *map, char *line)
{
	int		i;
	int		done;
	int		check;
	int		len;

	help_var(&i, &done, &check, &len);
	while (line[++i])
	{
		if (is_alpha(line[i]) || line[1] != ' ')
			return (2);
		else if (is_digit(line[i]) && !done)
		{
			if (check == 0 && ++check)
				map->width = ft_atoi(&line[i], &len);
			else if (check && ++done)
				map->height = ft_atoi(&line[i], &len);
			i += len - 1;
		}
		else if (done && is_digit(line[i]))
			return (3);
	}
	if (!done)
		return (4);
	return (0);
}
