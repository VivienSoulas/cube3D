#include "cub3D.h"

// int	ft_read_map(t_cub3D *cub)
// {
//     printf("reading map\n");
//     cub->map = malloc(sizeof(t_map));
//     if (!cub->map)
//         return (1);

//     // Allocate for a bigger map (e.g., 20x20)
//     int map_height = 20;
//     int map_width = 20;
//     cub->map->grid = malloc(sizeof(char*) * (map_height + 1));
//     if (!cub->map->grid)
//         return (1);

//     // Example: a valid, closed map with some rooms and corridors
//     cub->map->grid[0]  = ft_strdup("11111111111111111111");
//     cub->map->grid[1]  = ft_strdup("10000000001100000001");
//     cub->map->grid[2]  = ft_strdup("10111111101111111001");
//     cub->map->grid[3]  = ft_strdup("10100000100000001001");
//     cub->map->grid[4]  = ft_strdup("10101110111110101001");
//     cub->map->grid[5]  = ft_strdup("10101010000010101001");
//     cub->map->grid[6]  = ft_strdup("10101011111010101001");
//     cub->map->grid[7]  = ft_strdup("10101010001010101001");
//     cub->map->grid[8]  = ft_strdup("10101010101010101001");
//     cub->map->grid[9]  = ft_strdup("10101010101010101001");
//     cub->map->grid[10] = ft_strdup("10101010101010101001");
//     cub->map->grid[11] = ft_strdup("10101010101010101001");
//     cub->map->grid[12] = ft_strdup("10101010101010101001");
//     cub->map->grid[13] = ft_strdup("10101010101010101001");
//     cub->map->grid[14] = ft_strdup("10101010101010101001");
//     cub->map->grid[15] = ft_strdup("10101010101010101001");
//     cub->map->grid[16] = ft_strdup("10101010101010101001");
//     cub->map->grid[17] = ft_strdup("10100000000000001001");
//     cub->map->grid[18] = ft_strdup("10111111111111111001");
//     cub->map->grid[19] = ft_strdup("11111111111111111111");
//     cub->map->grid[20] = NULL;
//     cub->map->width = map_width;
//     cub->map->height = map_height;

//     // Place player inside the map, not in a wall
// 	// E = 0, dirx = 1, diry = 0
// 	// N = 90, dirx = 0, diry = -1
// 	// W = 180, dirx = -1, diry = 0
// 	// S = 270, dirx = 0, diry = 1
//     cub->player->pos_x = 2;
//     cub->player->pos_y = 2;
//     cub->player->start_dir = 'E';
//     cub->player->angle = 0;

// 	// cub->dda->dirx = cos(cub->player->radians_angle);
// 	// cub->dda->diry = -sin(cub->player->radians_angle);
// 	// cub->dda->planex = sin(cub->player->radians_angle) * 0.66;
// 	// cub->dda->planey = cos(cub->player->radians_angle) * 0.66;

//     cub->ceiling_color = 0x0000FF;
//     cub->floor_color = 0x00FF00;

//     // Texture paths (make sure these files exist in your project)
//     cub->textures->north_path = "textures/North.xpm";
//     cub->textures->south_path = "textures/South.xpm";
//     cub->textures->east_path  = "textures/East.xpm";
//     cub->textures->west_path  = "textures/West.xpm";

//     return (0);
// }

int	ft_read_map(t_cub3D *cub)
{
    printf("reading simple map\n");
    cub->map = malloc(sizeof(t_map));
    if (!cub->map)
        return (1);

    // Simple 10x10 map for testing DDA
    int map_height = 10;
    int map_width = 10;
    cub->map->grid = malloc(sizeof(char*) * (map_height + 1));
    if (!cub->map->grid)
        return (1);

    // Simple rectangular room with walls
    cub->map->grid[0] = ft_strdup("1111111111");
    cub->map->grid[1] = ft_strdup("1000000001");
    cub->map->grid[2] = ft_strdup("10N0000001");
    cub->map->grid[3] = ft_strdup("1001110001");
    cub->map->grid[4] = ft_strdup("1001110001");
    cub->map->grid[5] = ft_strdup("1001110001");
    cub->map->grid[6] = ft_strdup("1000000001");
    cub->map->grid[7] = ft_strdup("1000000001");
    cub->map->grid[8] = ft_strdup("1000000001");
    cub->map->grid[9] = ft_strdup("1111111111");
    cub->map->grid[10] = NULL;
    cub->map->width = map_width;
    cub->map->height = map_height;

    // Place player in open area (avoid the wall obstacle)
    cub->player->pos_x = 2.5;
    cub->player->pos_y = 2.5;
    cub->player->start_dir = 'E';  // Face East instead of North
    cub->player->angle = 0;        // 0° = East
	cub->player->radians_angle = cub->player->angle * M_PI / 180;

	// initialise the dda according to player's orientation
	cub->dda->dirx = cos(cub->player->radians_angle);
	cub->dda->diry = -sin(cub->player->radians_angle);
	cub->dda->planex = sin(cub->player->radians_angle) * 0.66;
	cub->dda->planey = cos(cub->player->radians_angle) * 0.66;

    cub->ceiling_color = 0x0000FF;
    cub->floor_color = 0x00FF00;

    // Texture paths (make sure these files exist in your project)
    cub->textures->north_path = "textures/North.xpm";
    cub->textures->south_path = "textures/South.xpm";
    cub->textures->east_path  = "textures/East.xpm";
    cub->textures->west_path  = "textures/West.xpm";

    return (0);
}