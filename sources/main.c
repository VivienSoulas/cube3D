/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:17:15 by vsoulas           #+#    #+#             */
/*   Updated: 2025/07/26 16:15:54 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	main(int ac, char **av)
{
	t_cube3D	*cube;

	if (ac != 2)
		return (ft_error(1), 1);
	cube = malloc(sizeof(t_cube3D));
	if (cube == NULL)
		return (ft_error(4), 1);

	cube->fd = open(av[1], O_RDONLY);
	if (cube->fd == -1)
		return (ft_free_cube(cube), ft_error(2), 1);
	// if (ft_map_parsing(fd) == 1)
	// 	return (ft_free_cube(cube), ft_error(3), 1);

	if (ft_initialise_mlx(cube) == 1)
		return (1);


	printf("My cube3D starts\n");
	return (ft_exit(cube), 0);
}
