/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instantiate_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:24:55 by natalia           #+#    #+#             */
/*   Updated: 2025/10/03 10:05:58 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	instantiate_data(t_data *input)
{
	input->map = NULL;
	input->no_texture = NULL;
	input->so_texture = NULL;
	input->ea_texture = NULL;
	input->we_texture = NULL;
	input->has_celling_color = false;
	input->has_floor_color = false;
	input->has_map_started = false;
	input->total_lines = 0;
	input->player_x = -1;
	input->player_y = -1;
	input->celling.r = -1;
	input->celling.g = -1;
	input->celling.b = -1;
	input->floor.r = -1;
	input->floor.g = -1;
	input->floor.b = -1;
}
