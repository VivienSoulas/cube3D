#include "cub3D.h"

int	ft_key_events(int key, t_cub3D *cub)
{
	if (key == 65307)
	{
		printf("Escape key pressed\n");
		ft_exit(cub);
		exit (1);
	}
	if (key == 119) // w
		ft_mini_map_render(cub, 0xff0000); //red
	else if (key == 97) // a
		ft_mini_map_render(cub, 0x00ff00); //green
	else if (key == 100) // d
		ft_mini_map_render(cub, 0x0000ff); //blue
	else if (key == 115) //s
		ft_mini_map_render(cub, 0xFF4500); //orange
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->mini_map->img_ptr, 0, 0); 
	printf("Key %d pressed\n", key);
	return (0);
}

int	ft_mouse_move_event(int x, int y, void *cub)
{
	int	init_x;

	init_x = x;
// mlx_mouse_get_pos(((t_cub3D *)cub)->window, &x, &y);
	mlx_mouse_get_pos(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, &x, &y);
	printf("Mouse in position x=%d\n", x);
	if (init_x < x)
		ft_mini_map_render(cub, 0x333333); // left
	else if (init_x > x)
		ft_mini_map_render(cub, 0xff4533); // right
	mlx_put_image_to_window(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, ((t_cub3D *)cub)->mini_map->img_ptr, 0, 0); 
	return (0);
}

void update_window_size(t_cub3D *cub)
{
    XWindowAttributes attr;
    XGetWindowAttributes((Display *)cub->mlx_ptr, (Window)cub->window, &attr);
    cub->window_width = attr.width;
    cub->window_height = attr.height;
}

int	ft_resize(void *cub)
{
	mlx_get_screen_size(((t_cub3D *)cub)->mlx_ptr, &((t_cub3D *)cub)->window_width, &((t_cub3D *)cub)->window_height);
	// update_window_size(((t_cub3D *)cub));

	mlx_destroy_image(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->img->img_ptr);
	ft_render_image(((t_cub3D *)cub));
	
	mlx_destroy_image(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->mini_map->img_ptr);
	ft_render_mini_map(((t_cub3D *)cub));
	
	mlx_destroy_image(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->weapon->weapon);
	ft_render_weapon(((t_cub3D *)cub));
	return (0);
}

int	ft_red_cross(void *cub)
{
	ft_exit(cub);
	exit(0);
	return (0);
}
