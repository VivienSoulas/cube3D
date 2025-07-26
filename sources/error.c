/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:02:21 by vsoulas           #+#    #+#             */
/*   Updated: 2025/07/24 16:02:27 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	ft_error(int id)
{
	write(2, "Error\n", 7);
	if (id == 1)
		write(2, "Not enough arguments\n", 22);
	if (id == 2)
		write(2, "Couldnt open map\n", 18);
	if (id == 3)
		write(2, "Invalid map\n", 13);
	if (id == 4)
		write(2, "malloc fail\n", 13);
}
