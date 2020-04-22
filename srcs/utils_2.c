/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:33:39 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/19 14:40:16 by tsantoni         ###   ########.fr       */
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
