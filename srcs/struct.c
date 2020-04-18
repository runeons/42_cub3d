/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:53:09 by tsantoni          #+#    #+#             */
/*   Updated: 2020/02/27 16:45:34 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map(t_map **map)
{
	if (!(*map = malloc(sizeof(t_map))))
		exit_err_1(-12);
	(*map)->tab = NULL;
	(*map)->cpy = NULL;
	(*map)->w = 0;
	(*map)->h = 0;
}

void	create_rgb(t_rgb **rgb)
{
	if (!(*rgb = malloc(sizeof(t_rgb))))
		exit_err_1(-12);
	(*rgb)->r = 0;
	(*rgb)->g = 0;
	(*rgb)->b = 0;
}

void	create_col(t_col **col)
{
	if (!(*col = malloc(sizeof(t_col))))
		exit_err_1(-12);
	(*col)->f = 0;
	(*col)->c = 0;
	(*col)->w = 0;
	(*col)->spr = 0;
}

void	create_win(t_win **win)
{
	if (!(*win = malloc(sizeof(t_win))))
		exit_err_1(-12);
	(*win)->ptr = NULL;
	(*win)->x = 0;
	(*win)->y = 0;
}

void	create_img(t_img **img)
{
	if (!(*img = malloc(sizeof(t_img))))
		exit_err_1(-12);
	(*img)->ptr = NULL;
	(*img)->add = NULL;
}

void	create_mlx(t_mlx **mlx)
{
	if (!(*mlx = malloc(sizeof(t_mlx))))
		exit_err_1(-12);
	(*mlx)->ptr = NULL;
	create_win(&((*mlx)->win));
	create_img(&((*mlx)->img));
}

void	create_vec(t_vec **vec)
{
	if (!(*vec = malloc(sizeof(t_vec))))
		exit_err_1(-12);
	(*vec)->x = 0;
	(*vec)->y = 0;
}

void	create_tmp(t_tmp **p)
{
	if (!(*p = malloc(sizeof(t_tmp))))
		exit_err_1(-12);
	(*p)->lst = NULL;
	(*p)->prev_x = -1;
	(*p)->clean_w = 0;
	(*p)->i = 0;
	(*p)->j = 0;
}

void	create_key(t_key **key_buf)
{
	if (!(*key_buf = malloc(sizeof(t_key))))
		exit_err_1(-12);
	(*key_buf)->left = 0;
	(*key_buf)->right = 0;
	(*key_buf)->up = 0;
	(*key_buf)->down = 0;
}

void	create_tex(t_tex **tex)
{
	if (!(*tex = malloc(sizeof(t_tex))))
		exit_err_1(-12);
	(*tex)->ptr = NULL;
	(*tex)->add = NULL;
	(*tex)->file = NULL;
	(*tex)->w = 0;
	(*tex)->h = 0;
	(*tex)->x = 0;
	(*tex)->y = 0;
}

void	create_sp(t_sp **sp)
{
	if (!(*sp = malloc(sizeof(t_sp))))
		exit_err_1(-12);
	(*sp)->x = 0;
	(*sp)->y = 0;
	(*sp)->dist = 0;
	(*sp)->img_add = NULL;
}

void	create_sp_inf(t_sp_inf **sp_inf)
{
	if (!(*sp_inf = malloc(sizeof(t_sp_inf))))
		exit_err_1(-12);
	create_sp(&((*sp_inf)->curr));
	(*sp_inf)->x = 0;
	(*sp_inf)->y = 0;
	(*sp_inf)->inv = 0;
	create_vec(&((*sp_inf)->trans));
	(*sp_inf)->screen = 0;
	(*sp_inf)->line_w = 0;
	(*sp_inf)->line_h = 0;
	create_vec(&((*sp_inf)->start));
	create_vec(&((*sp_inf)->end));
	(*sp_inf)->move_screen = 0;
}

void	create_bmp(t_bmp **bmp)
{
	if (!(*bmp = malloc(sizeof(t_bmp))))
		exit_err_1(-12);
	(*bmp)->fd = 0;
	(*bmp)->fsize = 0;
	(*bmp)->zero = 0;
	(*bmp)->offset = 0;
	(*bmp)->hsize = 0;
	(*bmp)->w = 0;
	(*bmp)->h = 0;
	(*bmp)->pln = 0;
	(*bmp)->bpp = 0;
}

void	init_scene(t_scene **s)
{
	(*s)->prp_dst = 0;
	(*s)->cam = 0;
	(*s)->hit = 0;
	(*s)->sde = 0;
	(*s)->line_h = 0;
	(*s)->pix_start = 0;
	(*s)->pix_end = 0;
	(*s)->tex_start = 0;
	(*s)->tex_end = 0;
	(*s)->zbuf = NULL;
	(*s)->spr_nb = 0;
	(*s)->save = 0;
	if (!((*s)->sp = malloc(sizeof(t_sp *) * 50)))
		exit_err_1(-12);
	ft_bzero((*s)->sp, sizeof(t_sp *) * 50);
	create_sp_inf(&((*s)->sp_inf));
	create_bmp(&((*s)->bmp));
	create_key(&((*s)->key_buf));
	if (!((*s)->elmts = malloc(sizeof(int) * 9)))
		exit_err_1(-12);
	ft_bzero((*s)->elmts, sizeof(int) * 9);
}

void	create_scene(t_scene **s)
{
	if (!(*s = malloc(sizeof(t_scene))))
		exit_err_1(-12);
	create_mlx(&((*s)->mlx));
	create_tmp(&((*s)->p));
	create_col(&((*s)->col));
	create_map(&((*s)->map));
	create_rgb(&((*s)->rgb));
	create_vec(&((*s)->pos));
	create_vec(&((*s)->dir));
	create_vec(&((*s)->pln));
	create_vec(&((*s)->ray));
	create_vec(&((*s)->sqr));
	create_vec(&((*s)->sde_dst));
	create_vec(&((*s)->dlt_dst));
	create_vec(&((*s)->stp));
	create_vec(&((*s)->wall));
	create_tex(&((*s)->tex_n));
	create_tex(&((*s)->tex_s));
	create_tex(&((*s)->tex_w));
	create_tex(&((*s)->tex_e));
	create_tex(&((*s)->tex_spr));
	init_scene(s);
}
