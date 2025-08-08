#include "cub3D.h"

int	ft_key_hooks(int key, t_cub3D *cub)
{
	if (key == 65307)
	{
		printf("Escape key pressed\n");
		ft_exit(cub);
		exit (1);
	}
	ft_movement_hooks(key, cub);
	ft_side_movement(key, cub);
	ft_orientation_change(key, cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->mini_map->img_ptr, 0, 0);
	printf("Key %d pressed\n", key);
	return (0);
}

// mlx_mouse_get_pos(((t_cub3D *)cub)->window, &x, &y);
int	ft_mouse_move_event(int x, int y, void *cub)
{
	mlx_mouse_get_pos(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, &x, &y);
	printf("Mouse in position x=%d\n", x);
	if (((t_cub3D *)cub)->mouse_x < x) // left movement
	{
		((t_cub3D *)cub)->mouse_x = x;
		printf("mouse movement to the left\n");
		ft_orientation_change_mouse(65361, cub);
		((t_cub3D *)cub)->mouse_x = x;
	}
	else if (((t_cub3D *)cub)->mouse_x > x)
	{
		((t_cub3D *)cub)->mouse_x = x;
		printf("mouse movement to the right\n");
		ft_orientation_change_mouse(65363, cub); // right movement
	}
	mlx_put_image_to_window(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, ((t_cub3D *)cub)->mini_map->img_ptr, 0, 0);
	return (0);
}

int	ft_resize(void *cub)
{
	mlx_destroy_image(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->img->img_ptr);
// find new window size;
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
