#include "mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCES);
	}
	return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    ft_square(int perimetre, int longueur, int largeur, t_data img)
{
    int rec;

    rec = 0;
    while (rec < perimetre)
    {
        if(rec < (perimetre /4))
        {
            my_mlx_pixel_put(&img,longueur, largeur , 0x00FF0000);
            longueur++;
        }
        if(rec >= (perimetre / 4) && rec < (perimetre / 2))
        {
            my_mlx_pixel_put(&img,longueur, largeur , 0x00FF0000);
            largeur++;
        }
        if(rec >= (perimetre / 2) && rec < (3 * (perimetre / 4)))
        {
            my_mlx_pixel_put(&img,longueur, largeur , 0x00FF0000);
            longueur--;
        }
        if(rec >= (3 * (perimetre / 4)))
        {
            my_mlx_pixel_put(&img,longueur, largeur , 0x00FF0000);
            largeur--;
        }
        rec++;
    }
}

void    ft_triangle(int perimetre, int  coordonne, t_data img)
{
    int tri;
    int i;
    int e;
    int a;
    int len;

    len = perimetre / 3;
    e = 0;
    i = 0;
    a = 0;
    tri = 0;
    while (tri < perimetre)
    {
        if(tri < len)
        {
            my_mlx_pixel_put(&img, coordonne + tri, coordonne , 0x00FF0000);
            i++;
        }
        else if (tri < len * 2)
        {
            my_mlx_pixel_put(&img, coordonne + (i) + (e/2) , coordonne - e , 0x00FF0000);
            i--;
            e++;
        }
        else if (tri < len * 3)
        {
            my_mlx_pixel_put(&img, coordonne + (i) + (e/2) , coordonne + a - len , 0x00FF0000);
            i--;
            e++;
            a++;
        }
        tri++;
    }
}
/*void    ft_cercle(int rayon, int coordonne, t_data img)
{
    int cercle;
    cercle = 0;
    while (cercle < (2 * 3.1416 * rayon))
    {
        my_mlx_pixel_put(&img, coordonne , coordonne , 0x00FF0000);
        cercle++;
    }
}*/

int	main(void)
{
	t_vars	vars;
	t_data	img;
    int longueur = 300;
    int largeur = 200;
    int rec = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1520, 1080, "So_long");
	img.img = mlx_new_image(vars.mlx, 1520, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	ft_square(1000,longueur, largeur, img);
    ft_triangle(900,  600, img);
    //ft_cercle(600, 900, img);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
}