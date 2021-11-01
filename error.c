#include "so_long.h"

void	free_str(char **str)
{
	int	line;

	line = 0;
	while (str[line])
	{
		free(str[line]);
		line++;
	}
	free(str);
}

void	error_close_map_exit(char **str)
{
	free_str(str);
	printf("Error, need at least one exit\n");
	exit(EXIT_FAILURE);
}

void	error_close_map_collectible(char **str)
{
	free_str(str);
	printf("Error, need at least one coin\n");
	exit(EXIT_FAILURE);
}

void	error_close_map_appear(char **str)
{
	free_str(str);
	printf("Error, need ONE point of appear in the map\n");
	exit(EXIT_FAILURE);
}

void	error_close_map(char **str)
{
	free_str(str);
	printf("Error, map isn't closed\n");
	exit(EXIT_FAILURE);
}
