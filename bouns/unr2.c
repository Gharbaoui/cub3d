/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:19:40 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/23 21:19:45 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		help_short3(char *str, int *i1, int *check)
{
	int i;

	i = *i1;
	*check = 0;
	while (str[++i] && (str[i] == ' ' || str[i] == ','))
		if (str[i] == ',')
			*check = 1;
	*i1 = i;
	return (0);
}

int		help_short4(char *str, int *len, int *color, int i)
{
	if (is_digit(str[i]))
	{
		*color = ft_atoi(&str[i], len);
		return (0);
	}
	return (-9);
}

int		help_short5(char *str, int *i1, int a, int *check)
{
	int i;

	i = *i1;
	if (a == 0)
	{
		*i1 = 0;
		*check = 0;
		i = *i1;
		while (str[i] == ' ' && str[i])
			i++;
		*i1 = i;
		return (0);
	}
	else if (a == 1)
	{
		while (str[++i])
			if (str[i] != ' ')
				return (-2);
		return (0);
	}
	return (0);
}

int		is_player(char *line, int *obj)
{
	int i;
	int pl;
	int obj1;

	i = -1;
	pl = 0;
	obj1 = 0;
	while (line[++i])
	{
		if (line[i] == 'W' || line[i] == 'N' ||
		line[i] == 'E' || line[i] == 'S')
			pl++;
		else if (line[i] == '2')
			obj1++;
	}
	*obj = obj1;
	return (pl);
}

int		short_help1(char **help, char *line)
{
	*help = line;
	return (0);
}
