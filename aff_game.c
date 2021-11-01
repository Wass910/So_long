#include "so_long.h"

t_vars	open_window(t_vars vars, int side)
{
	int	i;
	int	count_line;

	count_line = 0;
	while (vars.map[count_line])
		count_line++;
	i = ft_strlen(vars.map[0]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, i * side, count_line * side, "So_long");
	return (vars);
}

t_vars	load_image(int s, t_vars vars)
{
	vars.img_perso = mlx_xpm_file_to_image(vars.mlx, "./xpm/hero.xpm", &s, &s);
	vars.img_map = mlx_xpm_file_to_image(vars.mlx, "./xpm/wall.xpm", &s, &s);
	vars.img_collect = mlx_xpm_file_to_image(vars.mlx, "./xpm/c.xpm", &s, &s);
	vars.img_exit = mlx_xpm_file_to_image(vars.mlx, "./xpm/exit.xpm", &s, &s);
	vars.img_floor = mlx_xpm_file_to_image(vars.mlx, "./xpm/f.xpm", &s, &s);
	return (vars);
}

void	aff_game(t_vars vars, int side)
{
	aff_map(vars, side);
	aff_perso(vars, side);
	aff_collect(vars, side);
	aff_exit(vars, side);
	aff_floor(vars, side);
}
