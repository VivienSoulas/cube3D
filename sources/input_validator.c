#include "../includes/cub3D.h"

 //check colors
 //check walls

int	check_map_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' || map[i][j] != '1'
				|| map[i][j] != 'N' || map[i][j] != 'S'
				|| map[i][j] != 'E' || map[i][j] != 'W')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
