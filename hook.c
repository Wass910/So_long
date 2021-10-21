#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_FAILURE);
	}
	return 0;
}

int	expose_hook(int x, int y, t_vars *vars)
{
	if (x < 640 && y < 480)
		printf("hello\n");
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_expose_hook(vars.win, expose_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);	
	mlx_loop(vars.mlx);
	return 0;
}