#ifndef MOVEMENT_H
# define MOVEMENT_H

// Forward declaration to avoid circular dependency
typedef struct s_cub3D t_cub3D;

// add t_mv to cub#d and to exit/free
typedef struct s_mvt
{
	
	int		movement_update;
	double	new_x;
	double	new_y;
}	t_mvt;

// hooks
int		ft_key_pressed(int key, t_cub3D *cub);
int		ft_key_released(int key, t_cub3D *cub);
int		ft_update_game(t_cub3D *cub);
int		ft_mouse_move_event(int x, int y, void *cub);

int		ft_red_cross(void *cub);

// movement
int		ft_movement_hooks(t_cub3D *cub);
int		ft_side_movement(t_cub3D *cub);
int		ft_orientation_change(t_cub3D *cub);
void	ft_orientation_change_mouse(int key, t_cub3D *cub);

#endif