/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:33:39 by tsantoni          #+#    #+#             */
/*   Updated: 2020/02/27 16:23:40 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_range(int nb, int min, int max)
{
	if (nb < min || nb > max)
		return (0);
	return (1);
}

unsigned int	convert_color(int r, int g, int b)
{
	unsigned int	res;

	res = b | g << 8 | r << 16 | 0x00 << 24;
	return (res);
}

int				ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

int				ft_atoi_ptr(char const *s, int *i)
{
	int res;

	res = 0;
	skip_space((char *)s, i);
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		res = res * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (res);
}
