/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:37:43 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/21 17:50:29 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		destroy_notify(t_scene *s)
{
	free(s->tex_n->file);
	free(s->tex_s->file);
	free(s->tex_w->file);
	free(s->tex_e->file);
	free(s->tex_spr->file);
	mlx_destroy_image(s->mlx->ptr, s->mlx->img->ptr);
	if (s->save == 0)
		mlx_destroy_window(s->mlx->ptr, s->mlx->win->ptr);
	exit(EXIT_SUCCESS);
	return (OK);
}

int		key_press(int key, t_scene *s)
{
	if (key == ESC)
		destroy_notify(s);
	if (key == KEY_Q || key == KEY_A)
		s->key_buf->left = 1;
	if (key == KEY_D)
		s->key_buf->right = 1;
	if (key == KEY_Z || key == KEY_W || key == KEY_UP)
		s->key_buf->up = 1;
	if (key == KEY_S || key == KEY_DOWN)
		s->key_buf->down = 1;
	if (key == KEY_LEFT)
		s->key_buf->rotate_left = 1;
	if (key == KEY_RIGHT)
		s->key_buf->rotate_right = 1;
	return (OK);
}

int		key_release(int key, t_scene *s)
{
	if (key == KEY_Q || key == KEY_A)
		s->key_buf->left = 0;
	if (key == KEY_D)
		s->key_buf->right = 0;
	if (key == KEY_Z || key == KEY_W || key == KEY_UP)
		s->key_buf->up = 0;
	if (key == KEY_S || key == KEY_DOWN)
		s->key_buf->down = 0;
	if (key == KEY_LEFT)
		s->key_buf->rotate_left = 0;
	if (key == KEY_RIGHT)
		s->key_buf->rotate_right = 0;
	return (OK);
}

int		key_dispatch(t_scene *s)
{
	mlx_do_sync(s->mlx->ptr);
	if (s->key_buf->rotate_left == 1)
		rotate_left(s);
	if (s->key_buf->rotate_right == 1)
		rotate_right(s);
	if (s->key_buf->up == 1)
		move_forward(s);
	if (s->key_buf->down == 1)
		move_backward(s);
	if (s->key_buf->left == 1)
		move_left(s);
	if (s->key_buf->right == 1)
		move_right(s);
	draw_img(s);
	return (OK);
}
