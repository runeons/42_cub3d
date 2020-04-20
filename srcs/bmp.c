/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 10:29:02 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/20 13:54:18 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_bmp(t_scene *s)
{
	s->bmp->fd = open("./img.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (s->bmp->fd == -1)
		exit_err_1(-4);
	s->bmp->zero = 0;
	s->bmp->offset = 54;
	s->bmp->hsize = 40;
	s->bmp->w = s->mlx->win->x;
	s->bmp->h = s->mlx->win->y;
	s->bmp->pln = 1;
	s->bmp->bpp = 32;
	s->bmp->fsize = s->bmp->offset + s->bmp->w * s->bmp->h;
}

void	write_pixel_data(t_scene *s)
{
	int	x;
	int	y;
	int	pix_start;

	y = 0;
	while (y < s->bmp->h)
	{
		x = 0;
		pix_start = (s->bmp->h - y) * s->bmp->w;
		while (x < s->bmp->w)
		{
			if (write(s->bmp->fd, &s->mlx->img->add[pix_start], 4) == -1)
				exit_err_1(-6);
			pix_start++;
			x++;
		}
		y++;
	}
}

int		write_header(t_scene *s)
{
	int	ret;

	ret = write(s->bmp->fd, "BM", 2);
	ret = write(s->bmp->fd, &s->bmp->fsize, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->zero, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->offset, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->hsize, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->w, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->h, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->pln, sizeof(short int));
	ret = write(s->bmp->fd, &s->bmp->bpp, sizeof(short int));
	ret = write(s->bmp->fd, &s->bmp->zero, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->zero, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->zero, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->zero, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->zero, sizeof(int));
	ret = write(s->bmp->fd, &s->bmp->zero, sizeof(int));
	return (ret);
}

void	save_bmp(t_scene *s)
{
	draw_img(s);
	init_bmp(s);
	if (write_header(s) == -1)
		exit_err_1(-2);
	write_pixel_data(s);
	close(s->bmp->fd);
	key_press(ESC, s);
}
