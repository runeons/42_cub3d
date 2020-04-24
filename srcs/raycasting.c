/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:31:32 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/23 17:11:01 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_values_from_ray(t_scene *s, int i)
{
	s->cam = 2 * (double)i / (double)s->mlx->win->x - 1;
	s->ray->x = s->dir->x + s->pln->x * s->cam;
	s->ray->y = s->dir->y + s->pln->y * s->cam;
	s->sqr->x = (int)s->pos->x;
	s->sqr->y = (int)s->pos->y;
	s->dlt_dst->x = fabs(1 / s->ray->x);
	s->dlt_dst->y = fabs(1 / s->ray->y);
	s->stp->x = s->ray->x < 0 ? -1 : 1;
	s->stp->y = s->ray->y < 0 ? -1 : 1;
	if (s->ray->x < 0)
		s->sde_dst->x = (s->pos->x - s->sqr->x) * s->dlt_dst->x;
	else
		s->sde_dst->x = (s->sqr->x + 1.0 - s->pos->x) * s->dlt_dst->x;
	if (s->ray->y < 0)
		s->sde_dst->y = (s->pos->y - s->sqr->y) * s->dlt_dst->y;
	else
		s->sde_dst->y = (s->sqr->y + 1.0 - s->pos->y) * s->dlt_dst->y;
	s->hit = 0;
}

void	cast_ray_further(t_scene *s)
{
	if (s->sde_dst->x < s->sde_dst->y)
	{
		s->sde_dst->x += s->dlt_dst->x;
		s->sqr->x += s->stp->x;
		s->sde = 0;
	}
	else
	{
		s->sde_dst->y += s->dlt_dst->y;
		s->sqr->y += s->stp->y;
		s->sde = 1;
	}
	if (s->map->tab[(int)s->sqr->y][(int)s->sqr->x] == '1')
		s->hit = 1;
}

void	locate_wall_start_and_end(t_scene *s)
{
	if (s->sde == 0)
		s->prp_dst = (s->sqr->x - s->pos->x + (1 - s->stp->x) / 2) / s->ray->x;
	else
		s->prp_dst = (s->sqr->y - s->pos->y + (1 - s->stp->y) / 2) / s->ray->y;
	s->line_h = (int)(s->mlx->win->y / (s->prp_dst));
	s->pix_start = -s->line_h / 2 + s->mlx->win->y / 2;
	s->tex_start = -s->line_h / 2 + s->mlx->win->y / 2;
	if (s->pix_start < 0)
		s->pix_start = 0;
	s->pix_end = s->line_h / 2 + s->mlx->win->y / 2;
	s->tex_end = s->line_h / 2 + s->mlx->win->y / 2;
	if (s->pix_end >= s->mlx->win->y)
		s->pix_end = s->mlx->win->y - 1;
	if (s->sde == 0)
		s->wall->x = s->pos->y + s->prp_dst * s->ray->y;
	else
		s->wall->x = s->pos->x + s->prp_dst * s->ray->x;
	s->wall->x -= floor(s->wall->x);
}

void	pick_wall_texture_color(t_scene *s, t_tex *t)
{
	t->x = s->wall->x * t->w;
	t->y = s->wall->y * t->h;
	s->col->w = ((unsigned int *)t->add)[t->x + t->y * t->w];
}

void	overwrite_world_pixel(t_scene *s, int i, int j)
{
	if (j < s->pix_start)
		s->mlx->img->add[i + j * s->mlx->win->x] = s->col->c;
	else if (j >= s->pix_start && j < s->pix_end)
	{
		s->wall->y = ((double)j - (double)s->tex_start) /
			((double)s->tex_end - (double)s->tex_start);
		if (s->sde == 1 && s->ray->y <= 0)
			pick_wall_texture_color(s, s->tex_s);
		else if (s->sde == 1 && s->ray->y > 0)
			pick_wall_texture_color(s, s->tex_n);
		else if (s->sde == 0 && s->ray->x >= 0)
			pick_wall_texture_color(s, s->tex_w);
		else if (s->sde == 0 && s->ray->x < 0)
			pick_wall_texture_color(s, s->tex_e);
		if (s->sde == 1)
			s->col->w = s->col->w >> 1 & 8355711;
		s->mlx->img->add[i + j * s->mlx->win->x] = s->col->w;
	}
	else if (j >= s->pix_end)
		s->mlx->img->add[i + j * s->mlx->win->x] = s->col->f;
}
