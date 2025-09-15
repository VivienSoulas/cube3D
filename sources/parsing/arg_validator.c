#include "../includes/cub3D.h"

void	check_arg_extension(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (ft_strncmp(&arg[len - 4], ".cub", 4) != 0)
	{
		printf("The map should have .cub extension");
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
