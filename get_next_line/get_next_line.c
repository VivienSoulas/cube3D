/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:10 by vsoulas           #+#    #+#             */
/*   Updated: 2025/07/25 17:16:14 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int	main(void)
//{
// 	int		fd2;
// 	int		i;
// 	char	*lineread;

//	fd2 = 0;
// 	i = 0;
// 	fd2 = open ("test.txt", O_RDONLY);
// 	if (fd2 < 0)
// 		return (1);
// 	while (i < 5)
// 	{
// 		lineread = get_next_line(fd2);
// 		printf("line %i from text 1 =\n", i);
// 		printf("|%s|\n", lineread);
// 		free(lineread);
// 		i++;
// 	}
// 	close(fd2);
// 	return (0);
// }

// 1. read() and copy all characters from the file fd until '/n' is found
// 2. extract the line from array to the new array (line) including '\n'
// 3. remove the char before '/n' et return the array with everything afterwards
char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (next_line != NULL)
			free_static(&next_line);
		return (NULL);
	}
	next_line = ft_read_and_copy(fd, next_line);
	if (next_line == NULL)
		return (NULL);
	line = ft_get_line(next_line);
	if (line == NULL)
	{
		free_static(&next_line);
		return (NULL);
	}
	next_line = ft_new_next_line(next_line);
	return (line);
}

// read the file fd
// check for '/n'in next_line
// join the buffer (buf) to the exiting string next_line
char	*ft_read_and_copy(int fd, char *next_line)
{
	int		bytesread;
	char	*buf;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (free_static(&next_line), NULL);
	bytesread = 1;
	while (bytesread != 0 && !ft_strchr_int(next_line, '\n'))
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buf);
			return (free_static(&next_line), NULL);
		}
		buf[bytesread] = '\0';
		next_line = ft_free_and_join(next_line, buf);
		if (next_line == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (next_line);
}

// extract the line from the array/string next_line including the '/n'
char	*ft_get_line(char *next_line)
{
	char	*line;
	int		i;

	if (next_line[0] == '\0')
		return (NULL);
	i = 0;
	while (next_line[i] != '\n' && next_line[i])
		i++;
	if (next_line[i] == '\0')
		i--;
	line = malloc (sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = next_line[i];
		i--;
	}
	return (line);
}

// create a new array and fill it with the remainng of text after '\n' (if any)
char	*ft_new_next_line(char *next_line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (next_line[i] != '\n' && next_line[i])
		i++;
	if (next_line[i] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	new_line = malloc (sizeof(char) * (ft_strlen(next_line) - i + 1));
	if (new_line == NULL)
	{
		free(next_line);
		return (NULL);
	}
	j = 0;
	i++;
	while (next_line[i])
		new_line[j++] = next_line[i++];
	new_line[j] = '\0';
	free(next_line);
	return (new_line);
}

