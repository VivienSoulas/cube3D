#include "cube3D.h"

int	ft_events(int key, t_cube3D *cube)
{
	if (key == 65307)
	{
		printf("Escape key pressed\n");
		ft_exit(cube);
		exit (1);
	}
	printf("Key %d pressed\n", key);
	return (0);
}
