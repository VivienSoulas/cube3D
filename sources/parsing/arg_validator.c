/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:04:49 by nmedeiro          #+#    #+#             */
/*   Updated: 2025/10/03 10:04:56 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_arg_extension(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (ft_strncmp(&arg[len - 4], ".cub", 4) != 0)
	{
		printf("The map should have .cub extension");
		return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Please put the correct amount of arguments");
		return (1);
	}
	if (check_arg_extension(argv[1]) == 1)
		return (1);
	return (0);
}
