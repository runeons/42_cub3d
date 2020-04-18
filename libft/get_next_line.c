/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:45:51 by tsantoni          #+#    #+#             */
/*   Updated: 2020/01/27 11:30:31 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_strdel(char *s)
{
	free(s);
	s = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char	tokeep[BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	int			read_value;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = ft_calloc_gnl(1)))
		return (-1);
	if (*tokeep)
		*line = ft_strjoinfree(tokeep, *line, 2);
	while (ft_haseol(*line) == 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		buf[read_value] = '\0';
		*line = ft_strjoinfree(*line, buf, 1);
		if (read_value < BUFFER_SIZE && ft_haseol(*line) == 0)
		{
			tokeep[0] = '\0';
			return (0);
		}
	}
	ft_cut_line_create_tokeep(*line, tokeep);
	return (1);
}
