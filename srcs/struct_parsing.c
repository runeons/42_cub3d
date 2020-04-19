/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:53:09 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/19 15:10:13 by tsantoni         ###   ########.fr       */
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

void	create_vec(t_vec **vec)
{
	if (!(*vec = malloc(sizeof(t_vec))))
		exit_err_1(-12);
	(*vec)->x = 0;
	(*vec)->y = 0;
}
