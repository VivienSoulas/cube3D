/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atributes_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:04:35 by nmedeiro          #+#    #+#             */
/*   Updated: 2025/10/17 11:47:53 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**split_and_trim(char *line)
{
	char	**rgb_color;
	char	*temp;
	int		i;

	i = 0;
	rgb_color = ft_split(line, ',');
	if (!rgb_color)
		return (NULL);
	while (rgb_color[i] != NULL)
	{
		temp = ft_strtrim(rgb_color[i], " \n");
		if (temp == NULL)
			return (free_array(rgb_color), NULL);
		free (rgb_color[i]);
		rgb_color[i] = ft_strdup(temp);
		if (rgb_color[i] == NULL)
		{
			free(temp);
			return (free_array(rgb_color), NULL);
		}
		free(temp);
		i++;
	}
	return (rgb_color);
}

bool	is_valid_color(char	**rgb_color)
{
	int	i;
	int	rgb;
	int	error;

	i = 0;
	error = 0;
	while (rgb_color[i])
	{
		if (!is_valid_number(rgb_color[i]))
		{
			printf("Error: invalid RGB component -> *%s*\n", rgb_color[i]);
			return (false);
		}
		rgb = ft_atoi_flag(rgb_color[i], &error);
		if (rgb < 0 || rgb > 255 || error == 1)
		{
			printf("Error: RGB out of range\n");
			return (false);
		}
		i++;
	}
	if (i != 3)
		return (printf("Error: wrong number of RGB components\n"), false);
	return (true);
}

int	*get_color_input(char *line)
{
	char	**rgb_color;
	int		*rgb;
	int		i;

	i = 0;
	rgb = 0;
	rgb_color = split_and_trim(line + 1);
	if (!rgb_color)
		return (printf ("Error on parsing collors\n"), NULL);
	if (is_valid_color(rgb_color))
	{
		rgb = ft_calloc(sizeof(int), 3);
		if (!rgb)
			return (free_array(rgb_color), NULL);
		while (rgb_color[i])
		{
			rgb[i] = ft_atoi(rgb_color[i]);
			i++;
		}
	}
	else
		return (free_array(rgb_color), NULL);
	return (free_array(rgb_color), rgb);
}

bool	are_attributes_initialized(t_data *data)
{
	if (!data->no_texture || !data->so_texture
		|| !data->we_texture || !data->ea_texture)
	{
		printf("Error: missing texture\n");
		return (true);
	}
	else if (data->celling.r == -1 && data->celling.g == -1
		&& data->celling.b == -1)
	{
		printf("Error: missing celling color\n");
		return (true);
	}
	else if (data->floor.r == -1 && data->floor.g == -1 && data->floor.b == -1)
	{
		printf("Error: missing floor color\n");
		return (true);
	}
	return (true);
}
