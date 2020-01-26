/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unr3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:21:31 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/23 21:22:58 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		str_cmp(char *s1, char *s2, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (s1[i] != s2[i])
			return (1);
	return (0);
}

int		is_alpha(char c)
{
	if (!is_digit(c) && c != ' ')
		return (1);
	else
		return (0);
}

int		is_digit(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int		ft_atoi(char *str, int *len)
{
	int i;
	int num;

	num = 0;
	i = -1;
	while (is_digit(str[++i]))
		num = (num * 10) + (str[i] - 48);
	*len = i;
	return (num);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}
