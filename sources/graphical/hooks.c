/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:45:04 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:45:05 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_pressed(int key, t_cub3D *cub)
{
	if (key == 65307)
	{
		ft_exit(cub);
		exit (55);
	}
	if (key == 65507)
		cub->mouse_on_off = !cub->mouse_on_off;
	cub->keypressed[key] = 1;
	return (0);
}

int	ft_key_released(int key, t_cub3D *cub)
{
	cub->keypressed[key] = 0;
	return (0);
}

// check time difference for flikering lanterns
int	ft_update_game(t_cub3D *cub)
{
	static struct timeval	last_update = {0, 0};
	long					time_diff;

	gettimeofday(&cub->now, NULL);
	if (ft_movement_hooks(cub))
		cub->movement_update = 1;
	if (ft_side_movement(cub))
		cub->movement_update = 1;
	if (ft_orientation_change(cub))
		cub->movement_update = 1;
	if (last_update.tv_sec != 0)
	{
		time_diff = (cub->now.tv_sec - last_update.tv_sec) * 1000000
			+ (cub->now.tv_usec - last_update.tv_usec);
		if (time_diff > 16667)
			cub->needs_update = 1;
	}
	else
		cub->needs_update = 1;
	if (cub->movement_update)
		cub->needs_update = 1;
	if (cub->needs_update)
		return (ft_update(cub), last_update = cub->now, cub->needs_update = 0);
	return (0);
}

int	ft_mouse_move_event(int x, int y, void *cub)
{
	int		center_x;
	int		center_y;
	int		mouse_delta_x;
	float	rotation_speed;

	(void)y;
	if (((t_cub3D *)cub)->mouse_on_off == 0)
		return (1);
	center_x = ((t_cub3D *)cub)->window_width / 2;
	center_y = ((t_cub3D *)cub)->window_height / 2;
	mouse_delta_x = x - center_x;
	if (mouse_delta_x > 1 || mouse_delta_x < -1)
	{
		mlx_mouse_move(((t_cub3D *)cub)->mlx_ptr,
			((t_cub3D *)cub)->window, center_x, center_y);
		rotation_speed = mouse_delta_x * -0.2f;
		((t_cub3D *)cub)->player->angle += rotation_speed;
		if (((t_cub3D *)cub)->player->angle >= 360)
			((t_cub3D *)cub)->player->angle -= 360;
		if (((t_cub3D *)cub)->player->angle < 0)
			((t_cub3D *)cub)->player->angle += 360;
		ft_update_dda_vector(((t_cub3D *)cub));
		((t_cub3D *)cub)->movement_update = 1;
	}
	return (0);
}

int	ft_red_cross(void *cub)
{
	ft_exit(cub);
	exit(0);
	return (0);
}
