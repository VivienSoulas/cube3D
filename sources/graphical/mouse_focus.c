/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_focus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:40:39 by vsoulas           #+#    #+#             */
/*   Updated: 2025/11/14 11:06:22 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_focus_in(void *cub)
{
	((t_cub3d *)cub)->mouse_on_off = true;
	mlx_mouse_hide(((t_cub3d *)cub)->mlx_ptr, ((t_cub3d *)cub)->window);
	return (0);
}

int	ft_focus_out(void *cub)
{
	((t_cub3d *)cub)->mouse_on_off = false;
	mlx_mouse_show(((t_cub3d *)cub)->mlx_ptr, ((t_cub3d *)cub)->window);
	return (0);
}
