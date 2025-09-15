#include "cub3D.h"

void	ft_exit(t_cub3D *cub)
{
	ft_destroy_texture(cub);
	if (cub->img)
	{
		if (cub->img->img_ptr)
			mlx_destroy_image(cub->mlx_ptr, cub->img->img_ptr);
	}
	if (cub->mini_map)
	{
		if (cub->mini_map->img_ptr)
			mlx_destroy_image(cub->mlx_ptr, cub->mini_map->img_ptr);
	}
	if (cub->window)
		mlx_destroy_window(cub->mlx_ptr, cub->window);
	if (cub->mlx_ptr)
	{
		mlx_destroy_display(cub->mlx_ptr);
		ft_free_set_null((void **)&cub->mlx_ptr);
	}
	ft_free_cub(&cub);
}

void	ft_destroy_texture(t_cub3D *cub)
{
	if (cub->textures)
	{
		if (cub->textures->north_img)
			mlx_destroy_image(cub->mlx_ptr, cub->textures->north_img);
		if (cub->textures->south_img)
			mlx_destroy_image(cub->mlx_ptr, cub->textures->south_img);
		if (cub->textures->east_img)
			mlx_destroy_image(cub->mlx_ptr, cub->textures->east_img);
		if (cub->textures->west_img)
			mlx_destroy_image(cub->mlx_ptr, cub->textures->west_img);
	}
}

void	ft_free_struct(t_cub3D **cub)
{
	if ((*cub)->img)
		ft_free_set_null((void **)&(*cub)->img);
	if ((*cub)->mini_map)
		ft_free_set_null((void **)&(*cub)->mini_map);
	if ((*cub)->textures)
		ft_free_set_null((void **)&(*cub)->textures);
	if ((*cub)->vector)
		ft_free_set_null((void **)&(*cub)->vector);
	if ((*cub)->dda)
		ft_free_set_null((void **)&(*cub)->dda);
	if ((*cub)->wall)
		ft_free_set_null((void **)&(*cub)->wall);
	if ((*cub)->player)
		ft_free_set_null((void **)&(*cub)->player);
}

void	ft_free_cub(t_cub3D **cub)
{
	if (!cub || !*cub)
		return ;
	if ((*cub)->fd > 0)
		close((*cub)->fd);
	ft_free_struct(cub);
	if ((*cub)->map)
	{
		if ((*cub)->map->grid)
			ft_free_array((*cub)->map->grid);
		ft_free_set_null((void **)&(*cub)->map);
	}
	ft_free_set_null((void **)&(*cub));
}
