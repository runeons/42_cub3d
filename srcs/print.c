/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:37:15 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/19 14:23:29 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_vec(t_vec *vec)
{
	printf("x - y : %.1f - %.1f\n", vec->x, vec->y);
}

void	print_one_tab(char *tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		write(1, &tab[i++], 1);
	write(1, "\n", 1);
}

void	print_map(t_scene *s)
{
	int i;

	i = -1;
	while (++i < s->map->h)
		print_one_tab(s->map->tab[i]);
}

void	print_cpy(t_scene *s)
{
	int i;

	i = 0;
	while (s->map->cpy[i])
	{
		if (s->map->cpy[i][0] == '\0')
			break;
		else 
			print_one_tab(s->map->cpy[i]);
		i++;
	}
}

void	print_list(t_list *lst)
{
	while (lst->next)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	printf("%s\n", lst->content);
}

void	print_map2(t_scene *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->map->h)
	{
		j = 0;
		while (j < s->map->w)
		{
			printf("i : %i, j : %i  -  %c\n", i, j, s->map->tab[i][j]);
			j++;
		}
		i++;
	}
}

void	print_cpy2(t_scene *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->map->h + 2)
	{
		j = 0;
		while (j < s->map->w + 1)
		{
			printf("i : %i, j : %i  -  %c\n", i, j, s->map->cpy[i][j]);
			j++;
		}
		i++;
	}
}	
