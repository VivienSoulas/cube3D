/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/28 09:29:09 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/02 12:26:32 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

bool	has_fd_opened(int	fd)
{
	if (fd < 0)
    {
        perror("Failure to open file\n");
        return (false);
    }
	return (true);
}

void	ft_exit(int	exit_code, char *line)
{
	printf("Before free line: %s\n", line); //remove, only for test
	if (line != NULL)
		free(line);
	exit(exit_code);
}
