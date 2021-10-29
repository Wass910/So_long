#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

void    error_close_map_exit(void)
{
    printf("Il doit y' avoir au moin une sortie ok bg\n");
    exit(EXIT_FAILURE);
}

void    error_close_map_collectible(void)
{
    printf("Il doit y' avoir au moin un collectible ok bg\n");
    exit(EXIT_FAILURE);
}

void    error_close_map_appear(void)
{
    printf("Il doit y' avoir uniquement un point d apparition c'est tout ok bg\n");
    exit(EXIT_FAILURE);
}

void    error_close_map(void)
{
    printf("Erreur la map n'est pas ferme\n");
    exit(EXIT_FAILURE);
}

void    verif_first_end_wall(char **str, int last_line, int lengh)
{
    while (lengh >= 0)
    {
        if (str[0][lengh] != '1')
            error_close_map();
        if (str[last_line][lengh] != '1')
            error_close_map();
        lengh--;
    }
}

void    check_lengh_line(char **str, int count_line)
{
    int lengh_first;

    lengh_first = ft_strlen(str[0]);
    while (count_line > 0)
    {
        if (ft_strlen(str[count_line]) != lengh_first)
        {
            free(str);
            printf("les lignes ne font pas tous la meme taille bg\n");
            exit(EXIT_FAILURE);
        }
        count_line--;
    }
}

void    wall_map(char **str, int count_ligne)
{
    int i;
    int count;
    int lengh;

    count = 1;
    i = 0;
    lengh = ft_strlen(str[0]) - 1;
    check_lengh_line(str, count_ligne);
    verif_first_end_wall(str, count_ligne, lengh);
    while (count < count_ligne)
    {
        if (str[count][0] != '1' || str[count][lengh] != '1')
            error_close_map();
        count++;
    }
}

void    inside_map(char **str, int count_line)
{
    int count;
    t_CheckMap CheckMap;
    int i;

    count = 1;
    CheckMap.exit = 0;
    CheckMap.appears = 0;
    CheckMap.collectible = 0;
    while (count <= count_line)
    {
        i = 1;
        while (str[count][i])
        {
            if (str[count][i] == 'P')
                CheckMap.appears++;
            if (str[count][i] == 'E')
                CheckMap.exit++;
            if (str[count][i] == 'C')
                CheckMap.collectible++;
            if(str[count][i] != 'E' && str[count][i] != 'P' && str[count][i] != 'C' &&
                str[count][i] != '0' && str[count][i] != '1')
            {
                free(str);
                printf("Character invalide dans la map t bete ou quoi\n");
                exit(EXIT_FAILURE);
            }
            i++;
        }
        count++;
    }
    if (CheckMap.appears != 1)
    {
        free(str);
        error_close_map_appear();
    }
    if (CheckMap.exit <= 0)
    {
        free(str);
        error_close_map_exit();
    }
    if (CheckMap.collectible <= 0)
    {
        free(str);
        error_close_map_collectible();
    }
}

void    ft_map_condition(char **str)
{
    int count_ligne;
    int lengh;

    count_ligne = 0;
    if (*str == NULL)
    {
        free(str);
        printf("pas de map\n");
        exit(EXIT_FAILURE);
    }
    lengh = ft_strlen(str[0]) - 1;
    while (str[count_ligne])
        count_ligne++;
    wall_map(str, --count_ligne);
    inside_map(str, --count_ligne);
    printf("la map est valide avec validation \n");
}

int parcing(int fd)
{
    char	*line;
    char *map;
    char **map_finish;
    
    get_next_line(fd, &map);
    while (get_next_line(fd, &line) > 0)
	{
        map = ft_strcat(map, line);
        free(line);
	}
    map_finish = ft_split(map, '|');
    free(map);
    ft_map_condition(map_finish);
    return (0);
}

int main(int ac, char **av)
{
    (void)ac;
    t_vars  vars;
    t_data	img;

    int fd = open(av[1], O_RDONLY);
    parcing(fd);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1520, 1080, "So_long");
    img.img = mlx_new_image(vars.mlx, 1520, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
    mlx_loop(vars.mlx);
    return 0;
}