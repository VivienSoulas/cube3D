#ifndef DDA_H
# define DDA_H

// Forward declaration to avoid circular dependency
typedef struct s_cub3D t_cub3D;

typedef struct s_wall
{
	double	wall_distance;
	double	mini_distance;
	int		hit_side;
	int		hit;
}	t_wall;

typedef struct s_dda
{
	int		mapX;
	int		mapY;
	int		mini_mapX;
	int		mini_mapY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	rayDirX;
	double	rayDirY;
	int		stepX;
	int		stepY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
}	t_dda;

void	ft_dda(t_cub3D *cub, double rayDistX, double rayDistY);

#endif