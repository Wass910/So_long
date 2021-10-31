#include "so_long.h"

void	error_close_map_exit(void)
{
	printf("Error, need at least one exit\n");
	exit(EXIT_FAILURE);
}

void	error_close_map_collectible(void)
{
	printf("Error, need at least one coin\n");
	exit(EXIT_FAILURE);
}

void	error_close_map_appear(void)
{
	printf("Error, need ONE point of appear in the map\n");
	exit(EXIT_FAILURE);
}

void	error_close_map(void)
{
	printf("Error, map isn't closed\n");
	exit(EXIT_FAILURE);
}
