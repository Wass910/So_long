#include "so_long.h"

int	mouse_hook(t_vars *vars)
{
	free_str(vars->map);
	mlx_destroy_image(vars->mlx, vars->img_map);
	mlx_destroy_image(vars->mlx, vars->img_perso);
	mlx_destroy_image(vars->mlx, vars->img_exit);
	mlx_destroy_image(vars->mlx, vars->img_floor);
	mlx_destroy_image(vars->mlx, vars->img_collect);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
