/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:20:51 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/21 10:28:43 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_cub(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (file[len - 1] == 'b' && file[len - 2] == 'u' &&
			file[len - 3] == 'c' && file[len - 4] == '.')
		return (1);
	else
		return (0);
}

int		check_xpm(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (file[len - 1] == 'm' && file[len - 2] == 'p' &&
			file[len - 3] == 'x' && file[len - 4] == '.')
		return (1);
	else
		return (0);
}

void	check_elements(t_scene *s)
{
	int j;

	j = 0;
	while (j < 8)
	{
		if (s->elmts[j] != 1)
			exit_err_1(-11);
		j++;
	}
	if (s->elmts[8] != 1)
		exit_err_1(-5);
}

int		count_elements(t_scene *s)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (j < 9)
	{
		n += s->elmts[j];
		j++;
	}
	return (n);
}

void	increment_elmts(t_scene *s, char c)
{
	if (c == 'R')
		s->elmts[0]++;
	if (c == 'C')
		s->elmts[1]++;
	if (c == 'F')
		s->elmts[2]++;
	if (c == 'N')
		s->elmts[3]++;
	if (c == 'S')
		s->elmts[4]++;
	if (c == 'W')
		s->elmts[5]++;
	if (c == 'E')
		s->elmts[6]++;
	if (c == 's')
		s->elmts[7]++;
	if (c == 'p')
		s->elmts[8]++;
	if (c == 'm')
		s->elmts[9]++;
}
