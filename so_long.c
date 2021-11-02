/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:30:31 by idhiba            #+#    #+#             */
/*   Updated: 2021/11/02 11:30:34 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_verif_arg(int argc, char **argv, int fd)
{
	int	i;

	if (fd == -1)
	{
		printf("Error, the map doesn't exist. Please enter a valid file\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
		exit(EXIT_FAILURE);
	i = ft_strlen(argv[1]);
	if (i < 4)
	{
		printf("Error, the map doesn't exist. Please enter a valid file\n");
		exit(EXIT_FAILURE);
	}
	i--;
	if (argv[1][i] != 'r' && argv[1][i - 1] != 'e' && argv[1][i - 2] != 'b' &&
		argv[1][i - 3] != '.')
	{
		printf("Error, the map have to finish in .ber.\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	fd = open(av[1], O_RDONLY);
	ft_verif_arg(ac, av, fd);
	vars = parcing(fd);
	vars = open_game(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
