/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:06:13 by tsantoni          #+#    #+#             */
/*   Updated: 2019/10/18 13:11:47 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	int		j;

	i = start;
	j = 0;
	if (!(sub = malloc(sizeof(char) * len + 1)))
		return (0);
	if (start > ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	while (i < ((int)start + (int)len) && s[i])
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
