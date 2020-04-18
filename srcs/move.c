/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:30:29 by tsantoni          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:41 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_forward(t_scene *s)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = s->pos->x + s->dir->x * MOVE_SPEED;
	new_pos_y = s->pos->y + s->dir->y * MOVE_SPEED;
	if (s->map->tab[(int)s->pos->y][(int)new_pos_x] != '1')
		s->pos->x = new_pos_x;
	if (s->map->tab[(int)new_pos_y][(int)s->pos->x] != '1')
		s->pos->y = new_pos_y;
	return (OK);
}

int		move_backward(t_scene *s)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = s->pos->x - s->dir->x * MOVE_SPEED;
	new_pos_y = s->pos->y - s->dir->y * MOVE_SPEED;
	if (s->map->tab[(int)s->pos->y][(int)new_pos_x] &&
			s->map->tab[(int)s->pos->y][(int)new_pos_x] != '1')
		s->pos->x = new_pos_x;
	if (s->map->tab[(int)new_pos_y][(int)s->pos->x] &&
			s->map->tab[(int)new_pos_y][(int)s->pos->x] != '1')
		s->pos->y = new_pos_y;
	return (OK);
}

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
