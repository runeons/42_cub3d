/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:37:27 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/21 10:42:33 by tsantoni         ###   ########.fr       */
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
		write(STDERR_FILENO, "Error: player starting position\n", 32);
	else if (err_nb == -6)
		write(STDERR_FILENO, "2 Error: write bmp pixel data\n", 25);
	else if (err_nb == -7)
		write(STDERR_FILENO, "Error: map file name\n", 21);
	else if (err_nb == -8)
		write(STDERR_FILENO, "Error: resolution\n", 18);
	else if (err_nb == -9)
		write(STDERR_FILENO, "Error: floor/ceiling\n", 21);
	else if (err_nb == -10)
		write(STDERR_FILENO, "Error: textures\n", 16);
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
		write(STDERR_FILENO, "Error: unknown character on map\n", 32);
	else if (err_nb == -17)
		write(STDERR_FILENO, "Error: map not closed\n", 22);
	else if (err_nb == -18)
		write(STDERR_FILENO, "Error: unkown element\n", 22);
	else if (err_nb == -19)
		write(STDERR_FILENO, "Error: map should be at the end\n", 32);
	else if (err_nb == -20)
		write(STDERR_FILENO, "Error: map should end the file in one block\n(player position cannot be on the edge)\n", 83);
	exit(EXIT_FAILURE);
}
