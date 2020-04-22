/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:16:15 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/22 09:40:03 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_max(int *nb, int max)
{
	if (*nb > max)
		*nb = max;
}

void			ft_min(int *nb, int min)
{
	if (*nb < min)
		*nb = min;
}

int				ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void			skip_space(char *line, int *i)
{
	while (line[*i] && ft_is_space(line[*i]))
		(*i)++;
}

void			skip_space_char(char *line, int *i, char c)
{
	while (line[*i] && ft_is_space(line[*i]))
		(*i)++;
	if (line[*i] && line[*i] == c)
		(*i)++;
}
