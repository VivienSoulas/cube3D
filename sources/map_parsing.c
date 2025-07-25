/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:02:29 by vsoulas           #+#    #+#             */
/*   Updated: 2025/07/25 17:20:54 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	ft_map_parsing(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
