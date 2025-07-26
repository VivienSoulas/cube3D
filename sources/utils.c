#include "cube3D.h"

int	ft_initialise_mlx(t_cube3D *cube)
{
	cube->mlx_ptr = NULL;
	cube->window = NULL;
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		return (ft_exit(cube), ft_error(4), 1);
	cube->window = mlx_new_window(cube->mlx_ptr,
			DEFAULT_WIDTH, DEFAULT_HEIGHT, "cube3D");
	if (cube->window == NULL)
		return (ft_exit(cube), ft_error(4), 1);
	mlx_key_hook(cube->window, ft_events, cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
