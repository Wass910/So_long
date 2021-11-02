/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:29:10 by idhiba            #+#    #+#             */
/*   Updated: 2021/11/02 11:29:12 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aff_map(t_vars vars, int side)
{
	int	count_line;
	int	count_charac;

	count_line = 0;
	while (vars.map[count_line])
	{
		count_charac = 0;
		while (vars.map[count_line][count_charac])
		{
			if (vars.map[count_line][count_charac] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img_map,
					count_charac * side, count_line * side);
			count_charac++;
		}
		count_line++;
	}
}

void	aff_perso(t_vars vars, int side)
{
	int	count_line;
	int	count_charac;

	count_line = 0;
	while (vars.map[count_line])
	{
		count_charac = 0;
		while (vars.map[count_line][count_charac])
		{
			if (vars.map[count_line][count_charac] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img_perso,
					count_charac * side, count_line * side);
			count_charac++;
		}
		count_line++;
	}
}

void	aff_collect(t_vars vars, int side)
{
	int	count_line;
	int	count_charac;

	count_line = 0;
	while (vars.map[count_line])
	{
		count_charac = 0;
		while (vars.map[count_line][count_charac])
		{
			if (vars.map[count_line][count_charac] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img_collect,
					count_charac * side, count_line * side);
			count_charac++;
		}
		count_line++;
	}
}

void	aff_exit(t_vars vars, int side)
{
	int	count_line;
	int	count_charac;

	count_line = 0;
	while (vars.map[count_line])
	{
		 count_charac = 0;
		while (vars.map[count_line][count_charac])
		{
			if (vars.map[count_line][count_charac] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img_exit,
					count_charac * side, count_line * side);
			count_charac++;
		}
		count_line++;
	}
}

void	aff_floor(t_vars vars, int side)
{
	int	count_line;
	int	count_charac;

	count_line = 0;
	while (vars.map[count_line])
	{
		count_charac = 0;
		while (vars.map[count_line][count_charac])
		{
			if (vars.map[count_line][count_charac] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img_floor,
					count_charac * side, count_line * side);
			count_charac++;
		}
		count_line++;
	}
}
