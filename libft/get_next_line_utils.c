/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:58:43 by tsantoni          #+#    #+#             */
/*   Updated: 2020/01/27 11:30:58 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int		ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc_gnl(int size)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
		res[i++] = '\0';
	return (res);
}

char	*ft_strjoinfree(char *s1, char *s2, int tofree)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	if (!(res = malloc(sizeof(char) * len)))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] && i < len)
		res[i++] = s2[j++];
	res[i] = '\0';
	if (tofree == 1 || tofree == 3)
		ft_strdel(s1);
	if (tofree == 2 || tofree == 3)
		ft_strdel(s2);
	return (res);
}

int		ft_haseol(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_cut_line_create_tokeep(char *line, char *tokeep)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (line && line[i] != '\n')
		i++;
	line[i] = '\0';
	if (line[i + 1])
		i++;
	while (line[i])
	{
		tokeep[j] = line[i];
		i++;
		j++;
	}
	tokeep[j] = '\0';
}
