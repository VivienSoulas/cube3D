/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:44:43 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/24 13:23:49 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

// Keyboard key codes
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_ESC		65307
# define KEY_CTRL		65507

// Forward declaration to avoid circular dependency
typedef struct s_cub3D	t_cub3d;

typedef struct s_mvt
{
	int		movement_update;
	double	new_x_hor;
	double	new_x_ver;
	double	new_y_hor;
	double	new_y_ver;
	double	final_v_x;
	double	final_v_y;
}	t_mvt;

// hooks
int		ft_key_pressed(int key, t_cub3d *cub);
int		ft_key_released(int key, t_cub3d *cub);
int		ft_update_game(t_cub3d *cub);
int		ft_mouse_move_event(int x, int y, void *cub);

// mouse focus
int		ft_focus_in(void *cub);
int		ft_focus_out(void *cub);

int		ft_red_cross(void *cub);

// movement
int		ft_movement_hooks(t_cub3d *cub);
int		ft_side_movement(t_cub3d *cub);
int		ft_orientation_change(t_cub3d *cub);
void	ft_orientation_change_mouse(int key, t_cub3d *cub);
void	ft_final_vector_mvt(t_cub3d *cub);

#endif