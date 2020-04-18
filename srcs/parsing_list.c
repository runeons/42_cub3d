/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:40:48 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/18 10:31:47 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_char(t_scene *s, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		increment_elmts(s, 'p');
	else if (c == '2')
	{
		if (s->spr_nb > 50)
			exit_err(s, -15);
		create_sp(&s->sp[s->spr_nb]);
		s->spr_nb++;
	}
	else if (c != '0' && c != '1' && ft_is_space(c) == 0)
		exit_err(s, -16);
}

int		get_clean_width(char *line)
{
	int	x;
	int	i;

	x = 0;
	i = -1;
	while (line[++i])
		if (line[i] == 'N' || line[i] == 'S' ||
				line[i] == 'W' || line[i] == 'E' ||
				line[i] == '0' || line[i] == '1' || line[i] == '2')
			x++;
	return (x);
}

char	*clean_line(char *line, t_scene *s)
{
	char	*cleaned;
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	if (!(cleaned = malloc(sizeof(char) * get_clean_width(line) + 1)))
		exit_err(s, -12);
	while (line[i])
	{
		skip_space(line, &i);
		check_map_char(s, line[i]);
		cleaned[j++] = line[i++];
	}
	cleaned[j] = '\0';
	return (cleaned);
}

int		fill_list(t_scene *s, char *line)
{
	if (s->p->lst == NULL)
		s->p->lst = ft_lstnew(line);
	else
		ft_lstadd_back(&s->p->lst, ft_lstnew(line));
	return (OK);
}

int		parse_list(t_scene *s, char *line, int fd)
{
	int	gnl;

	fill_list(s, clean_line(line, s));
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		fill_list(s, clean_line(line, s));
		free(line);
	}
	if (gnl == 0)
		free(line);
	if (gnl == -1)
		exit_err(s, 2);
	return (OK);
}
