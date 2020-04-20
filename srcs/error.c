/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:37:27 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/20 14:30:15 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_err_1(int err_nb)
{
	if (err_nb > 0)
		perror("Error ");
	else if (err_nb == -1)
		write(STDERR_FILENO, "Error: arguments\n", 17);
	else if (err_nb == -2)
		write(STDERR_FILENO, "2 Error: saving as bmp\n", 17);
	else if (err_nb == -3)
		write(STDERR_FILENO, "3 Error: map size\n", 20);
	else if (err_nb == -4)
		write(STDERR_FILENO, "2 Error: open bmp file\n", 17);
	else if (err_nb == -5)
		write(STDERR_FILENO, "5 Error: starting position\n", 25);
	else if (err_nb == -6)
		write(STDERR_FILENO, "2 Error: write bmp pixel data\n", 25);
	else if (err_nb == -7)
		write(STDERR_FILENO, "Error: map file name\n", 21);
	else if (err_nb == -8)
		write(STDERR_FILENO, "8 Error: resolution\n", 20);
	else if (err_nb == -9)
		write(STDERR_FILENO, "9 Error: floor/ceiling\n", 17);
	else if (err_nb == -10)
		write(STDERR_FILENO, "0 Error: texture\n", 20);
	else if (err_nb == -11)
		write(STDERR_FILENO, "Error: elements number\n", 24);
	else if (err_nb == -12)
		write(STDERR_FILENO, "Error: memory allocation failure\n", 30);
	else if (err_nb == -13)
		write(STDERR_FILENO, "Error: mlx\n", 11);
	else if (err_nb == -14)
		write(STDERR_FILENO, "Error: mlx textures\n", 20);
	else if (err_nb == -15)
		write(STDERR_FILENO, "Error: max sprites 50\n", 20);
	else if (err_nb == -16)
		write(STDERR_FILENO, "Error: map character\n", 20);
	else if (err_nb == -17)
		write(STDERR_FILENO, "Error: map not closed\n", 22);
	else if (err_nb == -18)
		write(STDERR_FILENO, "Error: unkown element\n", 22);
	exit(EXIT_FAILURE);
}
