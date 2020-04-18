/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:13:39 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/18 10:32:11 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprite(t_scene *s, int i, int j)
{
	s->sp[s->spr_nb]->x = j + 0.5;
	s->sp[s->spr_nb]->y = i + 0.5;
	s->sp[s->spr_nb]->dist = (s->pos->x - s->sp[s->spr_nb]->x) * (s->pos->x -
			s->sp[s->spr_nb]->x) + (s->pos->y - s->sp[s->spr_nb]->y) *
		(s->pos->y - s->sp[s->spr_nb]->y);
	s->sp[s->spr_nb]->img_add = s->mlx->img->add;
	printf("pos : %f|%f - spr_nb : %i\n", s->sp[s->spr_nb]->x,
			s->sp[s->spr_nb]->y, s->spr_nb);
	s->spr_nb++;
}

void	init_player(t_scene *s, int i, int j)
{
	s->pos->x = j + 0.5;
	s->pos->y = i + 0.5;
	if (s->map->tab[i][j] == 'E' || s->map->tab[i][j] == 'W')
		s->dir->x = 1;
	s->dir->x *= (s->map->tab[i][j] == 'W') ? -1 : 1;
	if (s->map->tab[i][j] == 'N' || s->map->tab[i][j] == 'S')
		s->dir->y = 1;
	s->dir->y *= (s->map->tab[i][j] == 'N') ? -1 : 1;
	if (s->dir->y != 0)
	{
		s->pln->x = s->dir->y * -0.66;
		s->pln->y = 0;
	}
	if (s->dir->x != 0)
	{
		s->pln->x = 0;
		s->pln->y = s->dir->x * 0.66;
	}
	printf("pos : %.1f - %.1f | dir : %.1f - %.1f | pln : %.2f - %.2f\n",
			s->pos->x, s->pos->y, s->dir->x, s->dir->y, s->pln->x, s->pln->y);
}

void	init_pos_on_map(t_scene *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s->spr_nb = 0;
	while (s->map->tab[i])
	{
		j = 0;
		while (s->map->tab[i][j])
		{
			if (s->map->tab[i][j] == '2')
				init_sprite(s, i, j);
			if (s->map->tab[i][j] == 'N' || s->map->tab[i][j] == 'S' ||
					s->map->tab[i][j] == 'E' || s->map->tab[i][j] == 'W')
				init_player(s, i, j);
			j++;
		}
		i++;
	}
}

void	get_map_size(t_scene *s)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = s->p->lst;
	while (s->p->lst->next)
	{
		s->map->h++;
		s->p->lst = s->p->lst->next;
	}
	s->map->h++;
	s->p->lst = tmp;
	while (s->p->lst->next)
	{
		len = ft_strlen(s->p->lst->content);
		if (s->p->prev_x == -1)
			s->p->prev_x = len;
		else if (s->p->prev_x != len)
			exit_err(s, -3);
		s->map->w = len;
		s->p->lst = s->p->lst->next;
	}
	s->p->lst = tmp;
}

int		fill_map(t_scene *s)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = s->p->lst;
	get_map_size(s);
	if (!(s->map->tab = malloc(sizeof(char *) * (s->map->h + 1))))
		exit_err(s, -12);
	ft_bzero(s->map->tab, sizeof(char *) * (s->map->h + 1));
	while (s->p->lst->next)
	{
		s->map->tab[i] = s->p->lst->content;
		s->p->lst = s->p->lst->next;
		free(tmp);
		tmp = s->p->lst;
		i++;
	}
	s->map->tab[i] = s->p->lst->content;
	return (OK);
}
