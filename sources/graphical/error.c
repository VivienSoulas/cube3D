/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 16:02:21 by vsoulas       #+#    #+#                 */
/*   Updated: 2025/08/20 15:06:51 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error(int id)
{
	printf("Error\n");
	// write(2, "Error\n", 7);
	if (id == 1)
		printf("Not enough arguments\n");
		//write(2, "Not enough arguments\n", 22);
	if (id == 2)
		printf("Couldnt open map\n");
		// write(2, "Couldnt open map\n", 18);
	if (id == 3)
		printf("Invalid map\n");
		// write(2, "Invalid map\n", 13);
	// if (id == 4)
	// 	write(2, "malloc fail\n", 13);
	// if (id == 5)
	// 	write(2, "Could not load texture file\n", 29);
}
