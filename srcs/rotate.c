/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:06:24 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/21 18:06:33 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rotate_right(t_scene *s)
{
	double	tmp_dir_x;
	double	tmp_pln_x;

	tmp_dir_x = s->dir->x;
	s->dir->x = s->dir->x * cos(ROT_SPEED) - s->dir->y * sin(ROT_SPEED);
	s->dir->y = tmp_dir_x * sin(ROT_SPEED) + s->dir->y * cos(ROT_SPEED);
	tmp_pln_x = s->pln->x;
	s->pln->x = s->pln->x * cos(ROT_SPEED) - s->pln->y * sin(ROT_SPEED);
	s->pln->y = tmp_pln_x * sin(ROT_SPEED) + s->pln->y * cos(ROT_SPEED);
	return (OK);
}

int		rotate_left(t_scene *s)
{
	double	tmp_dir_x;
	double	tmp_pln_x;

	tmp_dir_x = s->dir->x;
	s->dir->x = s->dir->x * cos(-ROT_SPEED) - s->dir->y * sin(-ROT_SPEED);
	s->dir->y = tmp_dir_x * sin(-ROT_SPEED) + s->dir->y * cos(-ROT_SPEED);
	tmp_pln_x = s->pln->x;
	s->pln->x = s->pln->x * cos(-ROT_SPEED) - s->pln->y * sin(-ROT_SPEED);
	s->pln->y = tmp_pln_x * sin(-ROT_SPEED) + s->pln->y * cos(-ROT_SPEED);
	return (OK);
}
