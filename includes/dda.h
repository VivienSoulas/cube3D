#ifndef DDA_H
# define DDA_H

// Forward declaration to avoid circular dependency
typedef struct s_cub3D t_cub3D;

typedef struct s_dda
{
	int		mapX;
	int		mapY;
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

int	ft_dda(t_cub3D *cub, double cameraX);

#endif