#include "so_long.h"

t_vars	ft_up(t_vars vars)
{
	int count_line;
	int count_charac;

	count_line = 0;
	while (vars.map[count_line])
    {
        count_charac = 0;
        while (vars.map[count_line][count_charac])
        {
            if (vars.map[count_line][count_charac] == 'P')
            {
				if(vars.map[count_line-1][count_charac] == '1')
					return (vars);
				if(vars.map[count_line - 1][count_charac] == 'E' && vars.collectible != 0)
					return (vars);
				if(vars.map[count_line - 1][count_charac] == 'C')
					vars.collectible--;
				if(vars.map[count_line - 1][count_charac] == 'E' && vars.collectible == 0)
				{
					vars.nb_move++;
					printf("nb_move = %d\n", vars.nb_move);
					printf("the end bg\n");
					exit(EXIT_SUCCESS);
				}
				vars.map[count_line][count_charac] = '0';
				vars.map[count_line - 1][count_charac] = 'P';
				aff_game(vars, 64);
				vars.nb_move++;
                return(vars);
            }
            count_charac++;
        }
        count_line++;
    }
	return (vars);
}

t_vars ft_right( t_vars vars)
{
	int count_line;
	int count_charac;

	count_line = 0;
	while (vars.map[count_line])
    {
        count_charac = 0;
        while (vars.map[count_line][count_charac])
        {
            if (vars.map[count_line][count_charac] == 'P')
            {
				if(vars.map[count_line][count_charac + 1] == '1')
					return (vars);
				if(vars.map[count_line][count_charac + 1] == 'E' && vars.collectible != 0)
					return (vars);
				if(vars.map[count_line][count_charac + 1] == 'C')
					vars.collectible--;
				if(vars.map[count_line][count_charac + 1] == 'E' && vars.collectible == 0)
				{
					vars.nb_move++;
					printf("nb_move = %d\n", vars.nb_move);
					printf("the end bg\n");
					exit(EXIT_SUCCESS);
				}
				vars.map[count_line][count_charac] = '0';
				vars.map[count_line][count_charac + 1] = 'P';
				aff_game(vars, 64);
				vars.nb_move++;
                return(vars);
            }
            count_charac++;
        }
        count_line++;
    }
	return (vars);
}

t_vars ft_left( t_vars vars)
{
	int count_line;
	int count_charac;

	count_line = 0;
	while (vars.map[count_line])
    {
        count_charac = 0;
        while (vars.map[count_line][count_charac])
        {
            if (vars.map[count_line][count_charac] == 'P')
            {
				if(vars.map[count_line][count_charac - 1] == '1')
					return (vars);
				if(vars.map[count_line][count_charac - 1] == 'E' && vars.collectible != 0)
					return (vars);
				if(vars.map[count_line][count_charac - 1] == 'C')
					vars.collectible--;
				if(vars.map[count_line][count_charac - 1] == 'E' && vars.collectible == 0)
				{
					vars.nb_move++;
					printf("nb_move = %d\n", vars.nb_move);
					printf("the end bg\n");
					exit(EXIT_SUCCESS);
				}
				vars.map[count_line][count_charac] = '0';
				vars.map[count_line][count_charac - 1] = 'P';
				aff_game(vars, 64);
				vars.nb_move++;
                return(vars);
            }
            count_charac++;
        }
        count_line++;
    }
	return (vars);
}

t_vars  ft_down( t_vars vars)
{
	int count_line;
	int count_charac;

	count_line = 0;
	while (vars.map[count_line])
    {
        count_charac = 0;
        while (vars.map[count_line][count_charac])
        {
            if (vars.map[count_line][count_charac] == 'P')
            {
				if(vars.map[count_line + 1][count_charac] == '1')
					return (vars);
				if(vars.map[count_line + 1][count_charac] == 'E' && vars.collectible != 0)
					return (vars);
				if(vars.map[count_line + 1][count_charac] == 'C')
					vars.collectible--;
				if(vars.map[count_line + 1][count_charac] == 'E' && vars.collectible == 0)
				{
					vars.nb_move++;
					printf("nb_move = %d\n", vars.nb_move);
					printf("the end bg\n");
					exit(EXIT_SUCCESS);
				}
				vars.map[count_line][count_charac] = '0';
				vars.map[count_line + 1][count_charac] = 'P';
				vars.nb_move++;
				aff_game(vars, 64);
                return(vars);
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
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 119)
	{	
		*vars = ft_up( *vars);
		printf("nb_move = %d\n", vars->nb_move);
		return 0;
	}
	if (keycode == 97)
	{
		*vars = ft_left( *vars);
		printf("nb_move = %d\n", vars->nb_move);
		return 0;
	}
	if (keycode == 115)
	{
		*vars = ft_down( *vars);
		printf("nb_move = %d\n", vars->nb_move);
		return 0;
	}
	if (keycode == 100)
	{
		*vars= ft_right( *vars);
		printf("nb_move = %d\n", vars->nb_move);
		return 0;
	}
	return 0;
}

int	mouse_hook(int button,int x,int y,t_vars *vars)
{
	(void)button;
	(void)x;
	(void)y;
	exit(EXIT_SUCCESS);
	return 0;
}