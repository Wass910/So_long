#include "mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
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
    int color;

    color = get_r(color);
    printf("%d\n", color);
    rec = 0;
    while (rec < perimetre)
    {
        if(rec < (perimetre /4))
        {
            my_mlx_pixel_put(&img,longueur, largeur , color);
            longueur++;
        }
        if(rec >= (perimetre / 4) && rec < (perimetre / 2))
        {
            my_mlx_pixel_put(&img,longueur, largeur , color);
            largeur++;
        }
        if(rec >= (perimetre / 2) && rec < (3 * (perimetre / 4)))
        {
            my_mlx_pixel_put(&img,longueur, largeur , color);
            longueur--;
        }
        if(rec >= (3 * (perimetre / 4)))
        {
            my_mlx_pixel_put(&img,longueur, largeur , color);
            largeur--;
        }
        rec++;
    }
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int longueur = 300;
    int largeur = 200;
    int rec = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	ft_square(1000,longueur, largeur, img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}