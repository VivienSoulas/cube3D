#include "cub3D.h"

void	ft_exit(t_cub3D *cub)
{
	if (cub->textures)
	{
		if (cub->textures->weapon)
			mlx_destroy_image(cub->mlx_ptr, cub->textures->weapon);
	}
	if (cub->mini_map)
	{
		if (cub->mini_map->img_ptr)
			mlx_destroy_image(cub->mlx_ptr, cub->mini_map->img_ptr);
		ft_free_set_NULL((void**)&cub->mini_map);
	}
	if (cub->window)
		mlx_destroy_window(cub->mlx_ptr, cub->window);
	if (cub->mlx_ptr)
	{
		mlx_destroy_display(cub->mlx_ptr);
		ft_free_set_NULL((void**)&cub->mlx_ptr);
	}
	ft_free_cub(&cub);
}

void	ft_free_cub(t_cub3D **cub)
{
	if (!cub || !*cub)
		return ;
	if ((*cub)->fd > 0)
		close((*cub)->fd);
	if ((*cub)->map)
	{
		ft_free_array((*cub)->map->grid);
		ft_free_set_NULL((void**)&(*cub)->map);
	}
	if ((*cub)->textures)
		ft_free_set_NULL((void**)&(*cub)->textures);
	ft_free_set_NULL((void**)&(*cub));
}
