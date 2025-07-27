#include "cub3D.h"

int	ft_create_map(t_cub3D *cub)
{
	cub->map = malloc(sizeof(t_map));
	if (!cub->map)
		return (1);
	cub->map->grid = malloc(sizeof(char*) * 6);
	if (!cub->map->grid)
		return (1);
	cub->map->grid[0] = ft_strdup("1111111");
	cub->map->grid[1] = ft_strdup("1000001");
	cub->map->grid[2] = ft_strdup("1000001");
	cub->map->grid[3] = ft_strdup("1000N01");
	cub->map->grid[4] = ft_strdup("1111111");
	cub->map->grid[5] = NULL;
	cub->map->width = 7;
	cub->map->height = 5;
	return (0);
}
