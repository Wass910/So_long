#include "so_long.h"

void	ft_check_access(t_vars vars)
{
	if (vars.appears != 1)
		error_close_map_appear(vars.map);
	if (vars.exit <= 0)
		error_close_map_exit(vars.map);
	if (vars.collectible <= 0)
		error_close_map_collectible(vars.map);
}

t_vars	check_character_inside(t_vars vars, int count, int i)
{
	if (vars.map[count][i] == 'P')
		vars.appears++;
	if (vars.map[count][i] == 'E')
		vars.exit++;
	if (vars.map[count][i] == 'C')
		vars.collectible++;
	if (vars.map[count][i] != 'E' && vars.map[count][i] != 'P'
		&& vars.map[count][i] != 'C' && vars.map[count][i] != '0'
		&& vars.map[count][i] != '1' && vars.map[count][i] != 'G')
	{
		free_str(vars.map);
		printf("Error, not valide character\n");
		exit(EXIT_FAILURE);
	}
	return (vars);
}

t_vars	inside_map(t_vars vars, int count_line)
{
	int	count;
	int	i;

	count = 1;
	vars.exit = 0;
	vars.appears = 0;
	vars.collectible = 0;
	while (count <= count_line)
	{
		i = 1;
		while (vars.map[count][i])
		{
			vars = check_character_inside(vars, count, i);
			i++;
		}
		count++;
	}
	ft_check_access(vars);
	return (vars);
}
