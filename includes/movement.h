#ifndef MOVEMENT_H
# define MOVEMENT_H

// Forward declaration to avoid circular dependency
typedef struct s_cub3D t_cub3D;

// hooks
int		ft_key_hooks(int key, t_cub3D *cub);
int		ft_mouse_move_event(int x, int y, void *cub);
int		ft_resize(void *cub);
int		ft_red_cross(void *cub);

// movement
void	ft_movement_hooks(int key, t_cub3D *cub);
void	ft_side_movement(int key, t_cub3D *cub);
void	ft_orientation_change(int key, t_cub3D *cub);
void	ft_orientation_change_mouse(int key, t_cub3D *cub);

#endif