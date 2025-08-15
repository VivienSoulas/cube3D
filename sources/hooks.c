#include "cub3D.h"

int	ft_key_pressed(int key, t_cub3D *cub)
{
	if (key == 65307)
	{
		ft_exit(cub);
		exit (55);
	}
	if (key == 65507)
		cub->mouse_on_off = !cub->mouse_on_off;
	cub->keypressed[key] = 1;
	return (0);
}

int	ft_key_released(int key, t_cub3D *cub)
{
	cub->keypressed[key] = 0;
	return (0);
}

int	ft_update_game(t_cub3D *cub)
{
	ft_movement_hooks(cub);
	ft_side_movement(cub);
	ft_orientation_change(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->mini_map->img_ptr, 0, 0);
	return (0);
}

int	ft_mouse_move_event(int x, int y, void *cub)
{
	int	center_x;
	int	center_y;
	int	mx;
	int	my;

	(void)y;
	if (((t_cub3D *)cub)->mouse_on_off == 0)
		return (1);
	mlx_mouse_get_pos(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, &mx, &my);
	center_x = ((t_cub3D *)cub)->window_width / 2;
	center_y = ((t_cub3D *)cub)->window_height / 2;
	mx = x - center_x;
	if (mx != 0)
	{
		mlx_mouse_move(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, center_x, center_y);
		if (mx > 5)
			ft_orientation_change_mouse(65361, cub);
		else if (mx < -5)
			ft_orientation_change_mouse(65363, cub);
	}
	mlx_put_image_to_window(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, ((t_cub3D *)cub)->mini_map->img_ptr, 0, 0);
	return (0);
}

//int	ft_resize(void *cub)
//{
//	mlx_destroy_image(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->img->img_ptr);
//// find new window size;
//	ft_render_image(((t_cub3D *)cub));

//	mlx_destroy_image(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->mini_map->img_ptr);
//	ft_render_mini_map(((t_cub3D *)cub));

//	mlx_destroy_image(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->weapon->weapon);
//	ft_render_weapon(((t_cub3D *)cub));
//	return (0);
//}

int	ft_red_cross(void *cub)
{
	ft_exit(cub);
	exit(0);
	return (0);
}
