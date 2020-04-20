/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 13:46:12 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/20 13:46:27 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sp_inf(t_scene *s, int n)
{
	s->sp_inf->curr->x = s->sp[n]->x;
	s->sp_inf->curr->y = s->sp[n]->y;
	s->sp_inf->curr->dist = s->sp[n]->dist;
	s->sp_inf->curr->img_add = s->mlx->img->add;
	s->sp_inf->x = 0;
	s->sp_inf->y = 0;
	s->sp_inf->inv = 0;
	s->sp_inf->trans->x = 0;
	s->sp_inf->trans->y = 0;
	s->sp_inf->screen = 0;
	s->sp_inf->line_w = 0;
	s->sp_inf->line_h = 0;
	s->sp_inf->start->x = 0;
	s->sp_inf->start->y = 0;
	s->sp_inf->end->x = 0;
	s->sp_inf->end->y = 0;
}
