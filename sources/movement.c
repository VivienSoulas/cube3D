#include "cub3D.h"

void	ft_movement_hooks(int key, t_cub3D *cub)
{
	int	new_y;

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
}

void	ft_side_movement(int key, t_cub3D *cub)
{
	int	new_x;

	if (key == 100) // d
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
}

void	ft_orientation_change(int key, t_cub3D *cub)
{
	(void)cub;
	if (key == 65363) // right arrow / mouse move right
	{
		printf("rotating to the right\n");
	}
	else if (key == 65361) // left arrow / mouse move left
	{
		printf("rotating to the left\n");
	}
}