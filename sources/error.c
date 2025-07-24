#include "cube3D.h"

void	ft_error(int id)
{
	write(2, "Error\n", 7);
	if (id == 1)
		write(2, "Not enough arguments\n", 22);
	if (id == 2)
		write(2, "Couldnt open map\n", 18);
	if (id == 3)
		write(2, "Invalid map\n", 13);
}