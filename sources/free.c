#include "cube3D.h"

void	ft_free_cube(t_cube3D *cube)
{
	close(cube->fd);
	if (cube)
		free(cube);
	cube = NULL;
}
