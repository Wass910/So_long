#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

t_vars	open_game(t_vars vars)
{
	vars = open_window(vars, 64);
	vars = load_image(64, vars);
	aff_game(vars, 64);
	return (vars);
}

void	ft_verif_arg(int argc, char **argv)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!argv[1][0] && !argv[1][1] && !argv[1][2] &&
		!argv[1][3] && !argv[1][4] && !argv[1][5] &&
		!argv[1][6])
	{
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(argv[1]) != 7)
		exit(EXIT_FAILURE);
	if (argv[1][0] != 'm' && argv[1][1] != 'a' && argv[1][2] != 'p' &&
		argv[1][3] != '.' && argv[1][4] != 'b' && argv[1][5] != 'e' &&
		argv[1][6] != 'r')
	{
		exit(EXIT_FAILURE);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	ft_verif_arg(ac, av);
	fd = open(av[1], O_RDONLY);
	vars = parcing(fd, vars);
	vars = open_game(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
