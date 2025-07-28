#include "cub3D.h"

int	ft_key_events(int key, t_cub3D *cub)
{
	int	new_x;
	int	new_y;

	if (key == 65307)
	{
		printf("Escape key pressed\n");
		ft_exit(cub);
		exit (1);
	}
	if (key == 119) // w
	{
		new_y = cub->player->pos_y - 0.5;
		if (cub->map->grid[(int)new_y][(int)cub->player->pos_x] != '1')
		{
			cub->player->pos_y -= 0.5;
			ft_mini_map_render(cub);
		}
		else
			printf("wall colision detected\n");
	}
	else if (key == 97) // a
	{
		new_x = cub->player->pos_x - 0.5;
		if (cub->map->grid[(int)cub->player->pos_y][(int)new_x] != '1')
		{
			cub->player->pos_x -= 0.5;
			ft_mini_map_render(cub);
		}
		else
			printf("wall colision detected\n");
	}
	else if (key == 100) // d
	{
		new_x = cub->player->pos_x + 0.5;
		if (cub->map->grid[(int)cub->player->pos_y][(int)new_x] != '1')
		{
			cub->player->pos_x += 0.5;
			ft_mini_map_render(cub);
		}
		else
			printf("wall colision detected\n");
	}
	else if (key == 115) //s
	{
		new_y = cub->player->pos_y + 0.5;
		if (cub->map->grid[(int)new_y][(int)cub->player->pos_x] != '1')
		{
			cub->player->pos_y += 0.5;
			ft_mini_map_render(cub);
		}
		else
			printf("wall colision detected\n");
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->mini_map->img_ptr, 0, 0);
	printf("Key %d pressed\n", key);
	return (0);
}

// mlx_mouse_get_pos(((t_cub3D *)cub)->window, &x, &y);
int	ft_mouse_move_event(int x, int y, void *cub)
{
	// int	init_x;

	// init_x = x;
	mlx_mouse_get_pos(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, &x, &y);
	printf("Mouse in position x=%d\n", x);
	// if (init_x < x)
	// 	ft_mini_map_render(cub, 0x333333); // left
	// else if (init_x > x)
	// 	ft_mini_map_render(cub, 0xff4533); // right
	// mlx_put_image_to_window(((t_cub3D *)cub)->mlx_ptr, ((t_cub3D *)cub)->window, ((t_cub3D *)cub)->mini_map->img_ptr, 0, 0);
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
