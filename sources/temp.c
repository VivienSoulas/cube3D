#include "cub3D.h"

int	ft_read_map(t_cub3D *cub)
{
	printf("reading map\n");
	cub->map = malloc(sizeof(t_map));
	if (!cub->map)
		return (1);
	cub->map->grid = malloc(sizeof(char*) * 10);
	if (!cub->map->grid)
		return (1);
	cub->map->grid[0] = ft_strdup("1111111");
	cub->map->grid[1] = ft_strdup("1001001");
	cub->map->grid[2] = ft_strdup("1000001");
	cub->map->grid[3] = ft_strdup("1110001");
	cub->map->grid[4] = ft_strdup("1000001");
	cub->map->grid[5] = ft_strdup("1000011");
	cub->map->grid[6] = ft_strdup("100N001");
	cub->map->grid[7] = ft_strdup("1001001");
	cub->map->grid[8] = ft_strdup("1111111");
	cub->map->grid[9] = NULL;
	cub->map->width = 7;
	cub->map->height = 9;

	cub->player->pos_x = 3;
	cub->player->pos_y = 5;
	// cub->player->start_dir = ;
	cub->ceiling_color = 0x0000FF;
	cub->floor_color = 0x00FF00;
	// cub->textures->north_path = ;
	// cub->textures->south_path = ;
	// cub->textures->east_path = ;
	// cub->textures->west_path = ;
	return (0);
}
