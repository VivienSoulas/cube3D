#include "cub3D.h"

int	ft_read_map(t_cub3D *cub)
{
    printf("reading map\n");
    cub->map = malloc(sizeof(t_map));
    if (!cub->map)
        return (1);

    // Allocate for a bigger map (e.g., 20x20)
    int map_height = 20;
    int map_width = 20;
    cub->map->grid = malloc(sizeof(char*) * (map_height + 1));
    if (!cub->map->grid)
        return (1);

    // Example: a valid, closed map with some rooms and corridors
    cub->map->grid[0]  = ft_strdup("11111111111111111111");
    cub->map->grid[1]  = ft_strdup("10000000001100000001");
    cub->map->grid[2]  = ft_strdup("10111111101111111001");
    cub->map->grid[3]  = ft_strdup("10100000100000001001");
    cub->map->grid[4]  = ft_strdup("10101110111110101001");
    cub->map->grid[5]  = ft_strdup("10101010000010101001");
    cub->map->grid[6]  = ft_strdup("10101011111010101001");
    cub->map->grid[7]  = ft_strdup("10101010001010101001");
    cub->map->grid[8]  = ft_strdup("10101010101010101001");
    cub->map->grid[9]  = ft_strdup("10101010101010101001");
    cub->map->grid[10] = ft_strdup("10101010101010101001");
    cub->map->grid[11] = ft_strdup("10101010101010101001");
    cub->map->grid[12] = ft_strdup("10101010101010101001");
    cub->map->grid[13] = ft_strdup("10101010101010101001");
    cub->map->grid[14] = ft_strdup("10101010101010101001");
    cub->map->grid[15] = ft_strdup("10101010101010101001");
    cub->map->grid[16] = ft_strdup("10101010101010101001");
    cub->map->grid[17] = ft_strdup("10100000000000001001");
    cub->map->grid[18] = ft_strdup("10111111111111111001");
    cub->map->grid[19] = ft_strdup("11111111111111111111");
    cub->map->grid[20] = NULL;
    cub->map->width = map_width;
    cub->map->height = map_height;

    // Place player inside the map, not in a wall
	// E = 0, dirX = 1, dirY = 0
	// N = 90, dirX = 0, dirY = -1
	// W = 180, dirX = -1, dirY = 0
	// S = 270, dirX = 0, dirY = 1
    cub->player->pos_x = 2;
    cub->player->pos_y = 2;
    cub->player->start_dir = 'N';
    cub->player->angle = 90;

    cub->ceiling_color = 0x0000FF;
    cub->floor_color = 0x00FF00;

    // Texture paths (make sure these files exist in your project)
    cub->textures->north_path = "textures/North.xpm";
    cub->textures->south_path = "textures/South.xpm";
    cub->textures->east_path  = "textures/East.xpm";
    cub->textures->west_path  = "textures/West.xpm";

    return (0);
}