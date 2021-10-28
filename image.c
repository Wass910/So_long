#include "mlx.h"

typedef struct	s_img {
	void  *img;      /* pointer qui permet d'identifier l'image */
	char  *img_str;  /* string contenant tous les pixels de l'image */
	int   bits;      /* nombre de bits par pixels */
	int   size_line; /*  taille de la img_str*/
	int   endian;    /* permet de signifier la fin d'une image*/
}               t_img;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_pixel
{
	int x;
	int y;
}				t_pixel;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return 0;
}

void	put_pixel_image(t_pixel pixel, char *str, int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int len;

	//len = WIN_LEN; /* En réalité, il s'agit de la longueur de votre image. Ici, mon image et ma fenêtre font la même taille */

	/* in this part you'll see how i decompose a decimal color in a third part decimal color rgb(255, 255, 255) */
	/* Dans cette partie, voici comment je decompose une couleur decimal en une couleur décimale en trois partie rgb(255, 255, 255) */
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;

	/* (pixel.x * 4) + (len * 4 * pixel.y) : cible le premier bit d'un pixel */
	str[(pixel.x * 4) + (len * 4 * pixel.y)] = b;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 1] = g;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 2] = r;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 3] = 0;
}

void			print_square(int left_corner_x, int left_corner_y, int len_in_pixels, t_img *img)
{
	t_pixel		pix;
	int			y_stop;
	int			x_stop;

	x_stop = left_corner_x + len_in_pixels;
	y_stop = left_corner_y + len_in_pixels;
	pix.y = left_corner_y;

	while (pix.y != y_stop)
	{
		pix.x = left_corner_x;
		while (pix.x != x_stop)
		{
			put_pixel_image(pix, img->img_str, 65280);
			pix.x++;
		}
		pix.y++;
	}
}

int	main(void)
{
	t_vars  vars;
	t_img   img;
	int		img_width;
	int		img_height;

    img_height = 400;
    img_width = 400;
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1520, 1080, "So_long");
    img.img = mlx_new_image(vars.mlx, 1520, 1080);
	img.img_str = "test.xpm";            
   // img = mlx_xpm_file_to_image(vars.mlx, img.img_str, &img_width, &img_height);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
    mlx_loop(vars.mlx);
}