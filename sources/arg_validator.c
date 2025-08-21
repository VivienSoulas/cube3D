#include "../includes/cub3D.h"

//remove in future
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (s == NULL)
// 		return (0);
// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

//remove in future
// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && (s2[i] != '\0' || s1[i] != '\0'))
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

void	check_arg_extension(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (ft_strncmp(&arg[len - 4], ".cub", 4) != 0)
	{
		printf("The map should have .cup extension");
		exit (1);
	}
}
void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Please put the correct amount of arguments");
		exit (1);
	}
	check_arg_extension(argv[1]);
}
