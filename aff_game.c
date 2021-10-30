#include "so_long.h"

t_vars  open_window(t_vars vars, int side)
{
    int i;
    int count_line;

    count_line = 0;
    while (vars.map[count_line])
        count_line++;
    i = ft_strlen(vars.map[0]);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, i*side, count_line*side, "So_long");
    return (vars);
}

t_vars  load_image(int side, t_vars vars)
{
    vars.img_perso = mlx_xpm_file_to_image(vars.mlx, "./textures/player-64.xpm", &side, &side);
    vars.img_map = mlx_xpm_file_to_image(vars.mlx, "./textures/wall-64.xpm", &side, &side);
    vars.img_collect = mlx_xpm_file_to_image(vars.mlx, "./textures/collectible-64.xpm", &side, &side);
    vars.img_exit = mlx_xpm_file_to_image(vars.mlx, "./textures/exit-64.xpm", &side, &side);
    vars.img_floor = mlx_xpm_file_to_image(vars.mlx, "./textures/bottom-64.xpm", &side, &side);
    return (vars);
}

void    aff_game(t_vars vars, int side)
{
    aff_map(vars, side);
    aff_perso( vars, side);
    aff_collect(vars,side);
    aff_exit(vars, side);
    aff_floor(vars, side);
}
