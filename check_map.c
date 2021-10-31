#include "so_long.h"


void	verif_first_end_wall(char **str, int last_line, int lengh)
{
	while (lengh >= 0)
	{
		if (str[0][lengh] != '1')
			error_close_map(str);
		if (str[last_line][lengh] != '1')
			error_close_map(str);
		lengh--;
	}
}

void	check_lengh_line(char **str, int count_line)
{
	int	lengh_first;

	lengh_first = ft_strlen(str[0]);
	while (count_line > 0)
	{
		if (ft_strlen(str[count_line]) != lengh_first)
		{
			free_str(str);
			printf("Error, the map must be rectangular\n");
			exit(EXIT_FAILURE);
		}
		count_line--;
	}
}

t_vars	wall_map(t_vars vars, int count_ligne)
{
	int	i;
	int	count;
	int	lengh;

	count = 1;
	i = 0;
	lengh = ft_strlen(vars.map[0]) - 1;
	check_lengh_line(vars.map, count_ligne);
	verif_first_end_wall(vars.map, count_ligne, lengh);
	while (count < count_ligne)
	{
		if (vars.map[count][0] != '1' || vars.map[count][lengh] != '1')
			error_close_map(vars.map);
		count++;
	}
	return (vars);
}

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
	if(vars.map[count][i] != 'E' && vars.map[count][i] != 'P' && vars.map[count][i] != 'C' &&
		vars.map[count][i] != '0' && vars.map[count][i] != '1')
	{
		free(vars.map);
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

t_vars	ft_map_condition(t_vars vars)
{
	int	count_ligne;
	int	lengh;

	count_ligne = 0;
	if (*vars.map == NULL)
	{
		free(vars.map);
		printf("Error, no map\n");
		exit(EXIT_FAILURE);
	}
	lengh = ft_strlen(vars.map[0]) - 1;
	while (vars.map[count_ligne])
		count_ligne++;
	vars = wall_map(vars, --count_ligne);
	vars = inside_map(vars, --count_ligne);
	return (vars);
}

t_vars	parcing(int fd, t_vars vars)
{
	char	*line;
	char	*map;

	vars.nb_move = 0;
	get_next_line(fd, &map);
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_strcat(map, line);
		free(line);
	}
	free(line);
	vars.map = ft_split(map, '|');
	free(map);
	vars = ft_map_condition(vars);
	return (vars);
}
