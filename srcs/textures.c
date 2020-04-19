/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:07:12 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/19 15:01:12 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures_add(t_scene *s)
{
	int		bpp;
	int		szl;
	int		edn;

	if (!(s->tex_n->add = mlx_get_data_addr(s->tex_n->ptr,
					&bpp, &szl, &edn)))
		exit_err_1(-14);
	if (!(s->tex_s->add = mlx_get_data_addr(s->tex_s->ptr,
					&bpp, &szl, &edn)))
		exit_err_1(-14);
	if (!(s->tex_w->add = mlx_get_data_addr(s->tex_w->ptr,
					&bpp, &szl, &edn)))
		exit_err_1(-14);
	if (!(s->tex_e->add = mlx_get_data_addr(s->tex_e->ptr,
					&bpp, &szl, &edn)))
		exit_err_1(-14);
	if (!(s->tex_spr->add = mlx_get_data_addr(s->tex_spr->ptr,
					&bpp, &szl, &edn)))
		exit_err_1(-14);
}

void	init_textures_ptr(t_scene *s)
{
	if (!(s->tex_n->ptr = mlx_xpm_file_to_image(s->mlx->ptr,
					s->tex_n->file, &s->tex_n->w, &s->tex_n->h)))
		exit_err_1(-14);
	if (!(s->tex_s->ptr = mlx_xpm_file_to_image(s->mlx->ptr,
					s->tex_s->file, &s->tex_s->w, &s->tex_s->h)))
		exit_err_1(-14);
	if (!(s->tex_w->ptr = mlx_xpm_file_to_image(s->mlx->ptr,
					s->tex_w->file, &s->tex_w->w, &s->tex_w->h)))
		exit_err_1(-14);
	if (!(s->tex_e->ptr = mlx_xpm_file_to_image(s->mlx->ptr,
					s->tex_e->file, &s->tex_e->w, &s->tex_e->h)))
		exit_err_1(-14);
	if (!(s->tex_spr->ptr = mlx_xpm_file_to_image(s->mlx->ptr,
					s->tex_spr->file, &s->tex_spr->w, &s->tex_spr->h)))
		exit_err_1(-14);
	get_textures_add(s);
}

char	*ft_substr_word(char *line, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	int		j;

	i = start;
	j = 0;
	if (!(sub = malloc(sizeof(char) * len + 1)))
		exit_err_1(-12);
	if (start > ft_strlen(line))
	{
		sub[0] = '\0';
		return (sub);
	}
	while (i < ((int)start + (int)len) && line[i] && ft_is_space(line[i]) == 0)
		sub[j++] = line[i++];
	sub[j] = '\0';
	return (sub);
}

int		get_check_tex(char **file, char *line, int *i)
{
	*file = ft_substr_word(line, *i, (int)ft_strlen(line) - *i);
	if (check_xpm(*file) == 0)
		exit_err_1(-10);
	if (open(*file, O_RDONLY) == -1)
		exit_err_1(-10);
	close(open(*file, O_RDONLY));
	return (OK);
}

int		parse_texture(t_scene *s, char *line, int *i, char c)
{
	skip_space(line, i);
	(*i) += 2;
	skip_space(line, i);
	if (c == 'N')
		get_check_tex(&s->tex_n->file, line, i);
	if (c == 'S')
		get_check_tex(&s->tex_s->file, line, i);
	if (c == 'W')
		get_check_tex(&s->tex_w->file, line, i);
	if (c == 'E')
		get_check_tex(&s->tex_e->file, line, i);
	if (c == 's')
		get_check_tex(&s->tex_spr->file, line, i);
	increment_elmts(s, c);
	return (OK);
}
