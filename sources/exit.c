#include "cube3D.h"

void	ft_exit(t_cube3D *cube)
{
	if (cube->window)
		mlx_destroy_window(cube->mlx_ptr, cube->window);
	if (cube->mlx_ptr)
		mlx_destroy_display(cube->mlx_ptr);
	if (cube->mlx_ptr)
	{
		free(cube->mlx_ptr);
		cube->mlx_ptr = NULL;
	}
	ft_free_cube(cube);
}
