/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:44:59 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:45:00 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
