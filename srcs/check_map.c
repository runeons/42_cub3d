/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:56:11 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/20 14:10:54 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map_row(t_scene *s, int i, int j)
{
	int	cpy_w;
	int	cpy_h;

	cpy_w = s->map->w + 1;
	cpy_h = s->map->h + 2;
	if (!(s->map->cpy[i] = malloc(sizeof(char) * (cpy_w + 1))))
		exit_err_1(-12);
	while (j < cpy_w)
	{
		if (j == 0 || i == 0 || i == cpy_h - 1)
			s->map->cpy[i][j] = '8';
		else
			s->map->cpy[i][j] = s->map->tab[i - 1][j - 1];
		j++;
	}
	s->map->cpy[i][j] = '\0';
}

void	copy_map(t_scene *s)
{
	int	i;
	int	j;
	int	cpy_h;

	i = 0;
	j = 0;
	cpy_h = s->map->h + 2;
	if (!(s->map->cpy = malloc(sizeof(char *) * (cpy_h + 1))))
		exit_err_1(-12);
	ft_bzero(s->map->cpy, sizeof(char *) * cpy_h);
	while (i < cpy_h)
	{
		j = 0;
		copy_map_row(s, i, j);
		i++;
	}
	s->map->cpy[i] = "\0";
}

int		check_map(t_scene *s, int x, int y)
{
	char	**map;
	int		check;

	map = s->map->cpy;
	check = 0;
	if (map[y][x] == '1' || map[y][x] == '3' || map[y][x] == '4')
		return (1);
	if (x == 0 || y == 0 || y == s->map->h + 2)
		return (0);
	if (map[y][x] == '\0' || map[y][x] == '8')
		return (0);
	if (map[y][x] == '0')
		map[y][x] = '3';
	if (map[y][x] == '2')
		map[y][x] = '4';
	check += check_map(s, x + 1, y);
	check += check_map(s, x, y + 1);
	check += check_map(s, x - 1, y);
	check += check_map(s, x, y - 1);
	if (check != 4)
		return (0);
	return (1);
}
