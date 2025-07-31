/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s1_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:17 by vsoulas           #+#    #+#             */
/*   Updated: 2025/07/25 17:08:00 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// modified strchr to return int (0 or 1) for bool
int	ft_strchr_int(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_free_and_join(char *s1, char *s2)
{
	char	*temp;

	if (s1 == NULL)
	{
		s1 = malloc (sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

void	free_static(char **s1)
{
	if (*s1 != NULL)
		free(*s1);
	*s1 = NULL;
}
