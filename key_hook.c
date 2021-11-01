#include "so_long.h"

t_vars	ft_up(t_vars vars)
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
			{
				if (vars.map[count_line - 1][count_charac] == '1')
					return (vars);
				if (vars.map[count_line - 1][count_charac] == 'E'
					&& vars.collectible != 0)
					return (vars);
				vars = new_map_up(vars, count_line, count_charac);
				return (vars);
			}
			count_charac++;
		}
		count_line++;
	}
	return (vars);
}

t_vars	ft_right( t_vars vars)
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
			{
				if (vars.map[count_line][count_charac + 1] == '1')
					return (vars);
				if (vars.map[count_line][count_charac + 1] == 'E'
					&& vars.collectible != 0)
					return (vars);
				vars = new_map_right(vars, count_line, count_charac);
				return (vars);
			}
			count_charac++;
		}
		count_line++;
	}
	return (vars);
}

t_vars	ft_left(t_vars vars)
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
			{
				if (vars.map[count_line][count_charac - 1] == '1')
					return (vars);
				if (vars.map[count_line][count_charac - 1] == 'E'
					&& vars.collectible != 0)
					return (vars);
				vars = new_map_left(vars, count_line, count_charac);
				return (vars);
			}
			count_charac++;
		}
		count_line++;
	}
	return (vars);
}

t_vars	ft_down( t_vars vars)
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
			{
				if (vars.map[count_line + 1][count_charac] == '1')
					return (vars);
				if (vars.map[count_line + 1][count_charac] == 'E'
					&& vars.collectible != 0)
					return (vars);
				vars = new_map_down(vars, count_line, count_charac);
				return (vars);
			}
			count_charac++;
		}
		count_line++;
	}
	return (vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		free_map(*vars);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 119)
		*vars = ft_up(*vars);
	if (keycode == 97)
		*vars = ft_left(*vars);
	if (keycode == 115)
		*vars = ft_down(*vars);
	if (keycode == 100)
		*vars = ft_right(*vars);
	if (keycode == 119 || keycode == 97
		|| keycode == 100 || keycode == 115)
		printf("number of move = %d\n", vars->nb_move);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)button;
	(void)x;
	(void)y;
	exit(EXIT_SUCCESS);
	return (0);
}
