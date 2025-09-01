/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_data.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/01 09:24:55 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/01 09:25:18 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void instantiate_data(t_input *input)
{
	input->map=NULL;
	input->no_texture = NULL;
	input->so_texture = NULL;
	input->ea_texture = NULL;
	input->we_texture = NULL;
	input->has_celling_color = false;
	input->has_floor_color = false;
	input->has_map_started = false;
	input->total_lines = 0;
}
