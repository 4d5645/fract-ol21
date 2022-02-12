#include "fractol.h"

int	mandelbrot_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = 0;
	yy = 0;
	i = 1;
	while (i < ITERATION)
	{
		temp = xx;
		xx = (xx * xx - yy * yy) + x;
		yy = (2 * temp * yy) + y;
		if (xx * xx + yy * yy > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->mlx_win, mlx->loopx, mlx->loopy,
				(mlx->color) + 0x00FFC0CB * i);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx->mlx, mlx->mlx_win, mlx->loopx, mlx->loopy, 0x000E0E0E);
	return (0);
}

int	mandelbrot(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymin + (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			mandelbrot_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (1);
}


void	start_mandelbrot(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 600, 600, "Fract'ol - Mandelbrot");
	mlx->xmin = -2;
	mlx->xmax = 2;
	mlx->ymin = -2;
	mlx->ymax = 2;
	mlx->color = 0;
	mandelbrot(mlx);
	mlx_loop(mlx->mlx);
}