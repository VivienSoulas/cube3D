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
	int		mapx;
	int		mapy;
	int		mini_mapx;
	int		mini_mapy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
}	t_dda;

void	ft_wall_distance(t_cub3D *cub);
void	ft_finding_wall(t_cub3D *cub);
void	ft_steps(t_cub3D *cub, double raydirx, double raydiry);
void	ft_dda(t_cub3D *cub, double raydistx, double raydisty);

#endif