#ifndef CUBE3D_H
# define CUBE3D_H

# define DEFAULT_WIDTH 1000
# define DEFAULT_HEIGHT 750

# include "libft.h"
# include "mlx.h"
// # include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>

typedef struct s_display
{
	int	width;
	int	height;
	int	zoom;
}	t_display;

typedef struct s_cube3D
{
	int			fd;
	void		*mlx_ptr;
	void		*window;
	t_display	*display;
}	t_cube3D;

void	ft_error(int id);
int		ft_map_parsing(int fd);
void	ft_free_cube(t_cube3D *cube);
void	ft_exit(t_cube3D *cube);
int		ft_initialise_mlx(t_cube3D *cube);
int		ft_events(int key, t_cube3D *cube);

#endif