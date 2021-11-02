/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:29:41 by idhiba            #+#    #+#             */
/*   Updated: 2021/11/02 11:29:43 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_vars vars)
{
	free_str(vars.map);
	mlx_destroy_image(vars.mlx, vars.img_map);
	mlx_destroy_image(vars.mlx, vars.img_perso);
	mlx_destroy_image(vars.mlx, vars.img_exit);
	mlx_destroy_image(vars.mlx, vars.img_floor);
	mlx_destroy_image(vars.mlx, vars.img_collect);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
