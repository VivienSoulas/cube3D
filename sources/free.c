#include "cub3D.h"

void	ft_free_set_null(void **data)
{
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_free_set_null((void **)&array[i]);
		i++;
	}
	ft_free_set_null((void **)&array);
}
