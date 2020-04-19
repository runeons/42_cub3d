/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 15:07:09 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/19 15:10:07 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	create_key(t_key **key_buf)
{
	if (!(*key_buf = malloc(sizeof(t_key))))
		exit_err_1(-12);
	(*key_buf)->left = 0;
	(*key_buf)->right = 0;
	(*key_buf)->up = 0;
	(*key_buf)->down = 0;
}
