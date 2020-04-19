/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:03:38 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/19 14:28:04 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

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

void	copy_map_row(t_scene *s, int i, int j)
{
	int	cpy_w;
	int	cpy_h;

	cpy_w = s->map->w + 1;
	cpy_h = s->map->h + 2;
	if (!(s->map->cpy[i] = malloc(sizeof(char) * (cpy_w + 1))))
		exit_err(s, -12);
	while (j < cpy_w)
	{
		if (j == 0 || i == 0 || i == cpy_h - 1)
			s->map->cpy[i][j] = '8';
		else
			s->map->cpy[i][j] = s->map->tab[i - 1][j - 1];
		j++;
	}
	s->map->cpy[i][j] = '\0';
}

void	copy_map(t_scene *s)
{
	int	i;
	int	j;
	int	cpy_h;

	i = 0;
	j = 0;
	cpy_h = s->map->h + 2;
	if (!(s->map->cpy = malloc(sizeof(char *) * (cpy_h + 1))))
		exit_err(s, -12);
	ft_bzero(s->map->cpy, sizeof(char *) * cpy_h);
	while (i < cpy_h)
	{
		j = 0;
		copy_map_row(s, i, j);
		i++;
	}
	s->map->cpy[i] = "\0";
}

int		check_map(t_scene *s, int x, int y)
{
	int	check;
	char	**map;

	check = 0;
	map = s->map->cpy;
	//printf("check [%i][%i] = %c\n", y, x, map[y][x]);
	if (map[y][x] == '1' || map[y][x] == '3' || map[y][x] == '4')
		return (1);
	if (x == 0 || y == 0 || y == s->map->h + 2)
		return (0);
	if (map[y][x] == '\0' || map[y][x] == '8')
		return (0);
	if (map[y][x] == '0')
		map[y][x] = '3';
	if (map[y][x] == '2')
		map[y][x] = '4';
	check += check_map(s, x + 1, y);
	check += check_map(s, x, y + 1);
	check += check_map(s, x - 1, y);
	check += check_map(s, x, y - 1);
	if (check != 4)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_scene		*s;
	int		check;

	s = NULL;
	if (ac < 2 || ac > 3)
		exit_err_1(-1);
	if (av[1] && check_cub(av[1]) == 0)
		exit_err_1(-1);
	if (av[2] && ft_strcmp(av[2], "--save") != 0)
		exit_err_1(-1);
	create_scene(&s);
	if (av[2])
		s->save = 1;
	parsing(s, open(av[1], O_RDONLY));
//	while (1);
	fill_map(s);
	init_pos_on_map(s);
	if (!(s->mlx->ptr = mlx_init()))
		exit_err(s, -13);
	if (!(s->mlx->win->ptr = mlx_new_window(s->mlx->ptr, s->mlx->win->x,
			s->mlx->win->y, "WELCOME")))
		exit_err(s, -13);
	print_map(s);
	printf("\n");
	copy_map(s);
	print_cpy(s);
	check = -1;
	if (check_map(s, s->pos->x + 0.5, s->pos->y + 0.5) == 0)
		exit_err_1(-17);
	init_textures_ptr(s);
	get_textures_add(s);
	if (s->save == 1)
		save_bmp(s);
	mlx_hook(s->mlx->win->ptr, 02, 1L << 0, key_press, s);
	mlx_hook(s->mlx->win->ptr, 03, 1L << 1, key_release, s);
	mlx_loop_hook(s->mlx->ptr, key_dispatch, s);
	printf("HERE 888\n");
	mlx_loop(s->mlx->ptr);
	printf("HERE 9\n");
	return (OK);
}
