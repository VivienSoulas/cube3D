/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:17:15 by vsoulas           #+#    #+#             */
/*   Updated: 2025/07/24 15:56:20 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

// ./cube3D map "Floor colour" "Ceiliing colour"
int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_error(1), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return(ft_error(2), 1);
	if (ft_map_parsing(fd) == 1)
		return(ft_error(3), 1);

	printf("My cube3D starts\n");
	return (close(fd), 0);
}
