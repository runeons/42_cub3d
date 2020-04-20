/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:03:38 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/20 13:44:48 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

void	manage_sprites(t_scene *s)
{
	int		n;
	int		stripe;

	n = 0;
	order_sprites(s);
	while (n < s->spr_nb)
	{
		init_sp_inf(s, n);
		cast_sprite(s);
		locate_sprite_start_and_end(s);
		stripe = s->sp_inf->start->x;
		while (stripe < s->sp_inf->end->x)
			overwrite_sprite_pixel(s, stripe++);
		n++;
	}
}

void	draw_world(t_scene *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->mlx->win->x)
	{
		j = -1;
		init_values_from_ray(s, i);
		while (s->hit == 0)
			cast_ray_further(s);
		locate_wall_start_and_end(s);
		while (++j < s->mlx->win->y)
			overwrite_world_pixel(s, i, j);
		s->zbuf[i] = s->prp_dst;
	}
}

void	draw_img(t_scene *s)
{
	int	bpp;
	int	szl;
	int	edn;

	if (!(s->mlx->img->ptr = mlx_new_image(s->mlx->ptr,
			s->mlx->win->x, s->mlx->win->y)))
		exit_err(s, -13);
	if (!(s->mlx->img->add = (int *)mlx_get_data_addr(s->mlx->img->ptr,
			&bpp, &szl, &edn)))
		exit_err(s, -13);
	draw_world(s);
	manage_sprites(s);
//	if (!(mlx_put_image_to_window(s->mlx->ptr, s->mlx->win->ptr,
//			s->mlx->img->ptr, 0, 0)))
//		exit_err(s, -13);
	mlx_put_image_to_window(s->mlx->ptr, s->mlx->win->ptr,
			s->mlx->img->ptr, 0, 0);
}

int		main(int ac, char **av)
{
	t_scene		*s;

	s = NULL;
	if (ac < 2 || ac > 3)
		exit_err_1(-1);
	if (av[1] && check_cub(av[1]) == 0)
		exit_err_1(-1);
	if (av[2] && ft_strcmp(av[2], "--save") != 0)
		exit_err_1(-1);
	create_scene(&s);
	if (!(s->mlx->ptr = mlx_init()))
		exit_err(s, -13);
	parsing(s, open(av[1], O_RDONLY));
	if (!(s->mlx->win->ptr = mlx_new_window(s->mlx->ptr, s->mlx->win->x,
			s->mlx->win->y, "CUB3D")))
		exit_err(s, -13);
	init_textures_ptr(s);
	if (av[2])
		save_bmp(s);
	mlx_hook(s->mlx->win->ptr, 02, 1L << 0, key_press, s);
	mlx_hook(s->mlx->win->ptr, 03, 1L << 1, key_release, s);
	mlx_loop_hook(s->mlx->ptr, key_dispatch, s);
	mlx_loop(s->mlx->ptr);
	return (OK);
}
