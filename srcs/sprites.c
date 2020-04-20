/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:51:27 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/20 13:46:00 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_sprites(t_scene *s, int n1, int n2)
{
	t_sp	*tmp;

	create_sp(&tmp);
	tmp->x = s->sp[n1]->x;
	tmp->y = s->sp[n1]->y;
	tmp->dist = s->sp[n1]->dist;
	tmp->img_add = s->sp[n1]->img_add;
	s->sp[n1]->x = s->sp[n2]->x;
	s->sp[n1]->y = s->sp[n2]->y;
	s->sp[n1]->dist = s->sp[n2]->dist;
	s->sp[n1]->img_add = s->sp[n2]->img_add;
	s->sp[n2]->x = tmp->x;
	s->sp[n2]->y = tmp->y;
	s->sp[n2]->dist = tmp->dist;
	s->sp[n2]->img_add = tmp->img_add;
	free(tmp);
}

void	order_sprites(t_scene *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->spr_nb)
	{
		s->sp[i]->dist = (s->pos->x - s->sp[i]->x) * (s->pos->x -
			s->sp[i]->x) + (s->pos->y - s->sp[i]->y) *
		(s->pos->y - s->sp[i]->y);
		i++;
	}
	i = 0;
	while (i < s->spr_nb)
	{
		j = i;
		while (j < s->spr_nb)
		{
			if (s->sp[i]->dist < s->sp[j]->dist)
				swap_sprites(s, i, j);
			j++;
		}
		i++;
	}
}

void	locate_sprite_start_and_end(t_scene *s)
{
	s->sp_inf->line_h = abs((int)(s->mlx->win->y / s->sp_inf->trans->y)) /
		H_DIV;
	s->sp_inf->start->y = -s->sp_inf->line_h / 2 + s->mlx->win->y / 2 +
		s->sp_inf->move_screen;
	if (s->sp_inf->start->y < 0)
		s->sp_inf->start->y = 0;
	s->sp_inf->end->y = s->sp_inf->line_h / 2 + s->mlx->win->y / 2 +
		s->sp_inf->move_screen;
	if (s->sp_inf->end->y >= s->mlx->win->y)
		s->sp_inf->end->y = s->mlx->win->y - 1;
	s->sp_inf->line_w = abs((int)(s->mlx->win->y / s->sp_inf->trans->y)) /
		W_DIV;
	s->sp_inf->start->x = -s->sp_inf->line_w / 2 + s->sp_inf->screen;
	if (s->sp_inf->start->x < 0)
		s->sp_inf->start->x = 0;
	s->sp_inf->end->x = s->sp_inf->line_w / 2 + s->sp_inf->screen;
	if (s->sp_inf->end->x >= s->mlx->win->x)
		s->sp_inf->end->x = s->mlx->win->x - 1;
}

void	cast_sprite(t_scene *s)
{
	s->sp_inf->x = s->sp_inf->curr->x - s->pos->x;
	s->sp_inf->y = s->sp_inf->curr->y - s->pos->y;
	s->sp_inf->inv = 1 / (s->pln->x * s->dir->y - s->dir->x * s->pln->y);
	s->sp_inf->trans->x = s->sp_inf->inv * (s->dir->y * s->sp_inf->x -
			s->dir->x * s->sp_inf->y);
	s->sp_inf->trans->y = s->sp_inf->inv * (-s->pln->y * s->sp_inf->x +
			s->pln->x * s->sp_inf->y);
	s->sp_inf->screen = (int)((s->mlx->win->x / 2) *
			(1 + s->sp_inf->trans->x / s->sp_inf->trans->y));
	s->sp_inf->move_screen = (int)(MOVE_SPRITE / s->sp_inf->trans->y);
}

void	overwrite_sprite_pixel(t_scene *s, int x)
{
	int	y;
	int	d;

	d = 0;
	y = 0;
	s->tex_spr->x = (int)((x - (-s->sp_inf->line_w / 2 + s->sp_inf->screen)) *
		256 * s->tex_spr->w / s->sp_inf->line_w) / 256;
	if (s->sp_inf->trans->y > 0 && x > 0 && x <
			s->mlx->win->x && s->sp_inf->trans->y < s->zbuf[x])
	{
		y = s->sp_inf->start->y;
		while (y < s->sp_inf->end->y)
		{
			d = (y - s->sp_inf->move_screen) * 256 - s->mlx->win->y *
				128 + s->sp_inf->line_h * 128;
			s->tex_spr->y = ((d * s->tex_spr->h) / s->sp_inf->line_h) / 256;
			if (s->tex_spr->y == -1)
				s->tex_spr->y = 0;
			s->col->spr = ((unsigned int *)s->tex_spr->add)[s->tex_spr->x +
				s->tex_spr->y * s->tex_spr->w];
			if (s->col->spr != 0)
				s->mlx->img->add[x + y * s->mlx->win->x] = s->col->spr;
			y++;
		}
	}
}
