#include "fractol.h"

int	mandelbrot_set(double x, double y, t_data *data)
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
			mlx_pixel_put(data->mlx, data->mlx_win, data->loopx, data->loopy,
				(data->color) + 0x00FFC0CB * i);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(data->mlx, data->mlx_win, data->loopx, data->loopy, 0x000E0E0E);
	return (0);
}

int	mandelbrot(t_data *data)
{
	double	x;
	double	y;

	data->loopx = 0;
	data->loopy = 0;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->loopy < HEIGHT)
	{
		while (data->loopx < WIDTH)
		{
			x = data->xmin + (data->loopx * ((data->xmax - data->xmin) / WIDTH));
			y = data->ymin + (data->loopy * ((data->ymax - data->ymin) / HEIGHT));
			mandelbrot_set(x, y, data);
			data->loopx++;
		}
		data->loopy++;
		data->loopx = 0;
	}
	mlx_hook(data->mlx_win, 17, 2, close_esc, (void *)0);
	mlx_loop(data->mlx);
	return (1);
}