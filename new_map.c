#include "so_long.h"

t_vars	new_map_up(t_vars vars, int count_line, int count_charac)
{
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
	return (vars);	
}

t_vars	new_map_right(t_vars vars, int count_line, int count_charac)
{
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
	return (vars);	
}

t_vars	new_map_left(t_vars vars, int count_line, int count_charac)
{
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
	return (vars);	
}

t_vars	new_map_down(t_vars vars, int count_line, int count_charac)
{
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
	aff_game(vars, 64);
	vars.nb_move++;
	return (vars);	
}