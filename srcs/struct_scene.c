/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 15:04:53 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/21 10:28:13 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	(*s)->save = 0;
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
	if (!((*s)->sp = malloc(sizeof(t_sp *) * 50)))
		exit_err_1(-12);
	ft_bzero((*s)->sp, sizeof(t_sp *) * 50);
	create_sp_inf(&((*s)->sp_inf));
	create_bmp(&((*s)->bmp));
	create_key(&((*s)->key_buf));
	if (!((*s)->elmts = malloc(sizeof(int) * 10)))
		exit_err_1(-12);
	ft_bzero((*s)->elmts, sizeof(int) * 10);
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
