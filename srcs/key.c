/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:37:43 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/20 13:57:54 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_scene *s)
{
	if (key == ESC)
	{
		free(s->tex_n->file);
		free(s->tex_s->file);
		free(s->tex_w->file);
		free(s->tex_e->file);
		free(s->tex_spr->file);
		mlx_destroy_image(s->mlx->ptr, s->mlx->img->ptr);
		mlx_destroy_window(s->mlx->ptr, s->mlx->win->ptr);
		exit(EXIT_SUCCESS);
	}
	if (key == KEYL || key == LEFT)
		s->key_buf->left = 1;
	if (key == KEYR || key == RIGHT)
		s->key_buf->right = 1;
	if (key == KEYU || key == UP)
		s->key_buf->up = 1;
	if (key == KEYD || key == DOWN)
		s->key_buf->down = 1;
	return (OK);
}

int		key_release(int key, t_scene *s)
{
	if (key == KEYL || key == LEFT)
		s->key_buf->left = 0;
	if (key == KEYR || key == RIGHT)
		s->key_buf->right = 0;
	if (key == KEYU || key == UP)
		s->key_buf->up = 0;
	if (key == KEYD || key == DOWN)
		s->key_buf->down = 0;
	return (OK);
}

int		key_dispatch(t_scene *s)
{
	if (s->key_buf->left == 1)
		rotate_left(s);
	if (s->key_buf->right == 1)
		rotate_right(s);
	if (s->key_buf->up == 1)
		move_forward(s);
	if (s->key_buf->down == 1)
		move_backward(s);
	draw_img(s);
	return (OK);
}
