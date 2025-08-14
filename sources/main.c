/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:17:15 by vsoulas           #+#    #+#             */
/*   Updated: 2025/08/08 13:34:00 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_cub3D	*cub;

	if (ac != 2)
		return (ft_error(1), 1);
	cub = ft_calloc(1, sizeof(t_cub3D));
	if (cub == NULL)
		return (ft_error(4), 1);
	if (ft_initialise_cub(cub, av) == 1)
		return (1);
	ft_initialise_mini_map(cub);
	if (ft_initialise_mlx(cub) == 1)
		return (1);
	mlx_hook(cub->window, 2, 1L << 0, ft_key_hooks, cub);
	mlx_hook(cub->window, 6, 1L << 6, ft_mouse_move_event, cub);
	mlx_hook(cub->window, 17, 0, ft_red_cross, cub);
	mlx_loop(cub->mlx_ptr);
	return (ft_exit(cub), 0);
}
