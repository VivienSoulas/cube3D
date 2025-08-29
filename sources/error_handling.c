/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/28 09:29:09 by natalia       #+#    #+#                 */
/*   Updated: 2025/08/29 13:41:58 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

bool	has_fd_opened(int	fd)
{
	if (fd < 0)
    {
        perror("Failure to open file");
        return (false);
    }
	return (true);
}

void	ft_exit(int	exit_code, char *line)
{
	if (line != NULL)
		free(line);
	exit(exit_code);
}
