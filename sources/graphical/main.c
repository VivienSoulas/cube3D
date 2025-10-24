/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:17:15 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/24 13:28:07 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_cub3d	*cub;

	if (ac != 2)
		return (ft_error(1), 1);
	cub = ft_calloc(1, sizeof(t_cub3d));
	if (cub == NULL)
		return (ft_error(4), 1);
	if (ft_initialise_cub(cub, ac, av) == 1)
		return (ft_exit(cub), 1);
	ft_initialise_mini_map(cub);
	if (ft_initialise_mlx(cub) == 1)
		return (ft_exit(cub), 1);
	mlx_hook(cub->window, 2, 1L << 0, ft_key_pressed, cub);
	mlx_hook(cub->window, 3, 1L << 1, ft_key_released, cub);
	mlx_hook(cub->window, 9, 1L << 21, ft_focus_in, cub);
	mlx_hook(cub->window, 10, 1L << 21, ft_focus_out, cub);
	mlx_hook(cub->window, 6, 1L << 6, ft_mouse_move_event, cub);
	mlx_loop_hook(cub->mlx_ptr, ft_update_game, cub);
	mlx_hook(cub->window, 17, 0, ft_red_cross, cub);
	mlx_loop(cub->mlx_ptr);
	return (ft_exit(cub), 0);
}
