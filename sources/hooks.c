#include "cub3D.h"

int	ft_events(int key, t_cub3D *cub)
{
	if (key == 65307)
	{
		printf("Escape key pressed\n");
		ft_exit(cub);
		exit (1);
	}
	if (key == 119) // w
		ft_mini_map_management(cub, 0xff0000); //red
	else if (key == 97) // a
		ft_mini_map_management(cub, 0x00ff00); //green
	else if (key == 100) // d
		ft_mini_map_management(cub, 0x0000ff); //blue
	else if (key == 115) //s
		ft_mini_map_management(cub, 0xFF4500); //orange
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->mini_map->img_ptr, 0, 0); 
	printf("Key %d pressed\n", key);
	return (0);
}
