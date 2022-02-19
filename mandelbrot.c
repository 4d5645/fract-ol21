/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:40:16 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:40:16 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	img_pix_put(t_data *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

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
			img_pix_put(data, data->iter_x, data->iter_y, (data->color) + 0x00FFC0CB * i);
			return (0);
		}
		i++;
	}
	img_pix_put(data, data->iter_x, data->iter_y, 0x000E0E0E);
	return (0);
}

/*
** Use nested loop
*/

int	mandelbrot(t_data *data)
{
	double	x;
	double	y;

	data->iter_x = 0;
	data->iter_y = 0;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->iter_y < HEIGHT)
	{
		while (data->iter_x < WIDTH)
		{
			x = data->xmin + (data->iter_x
					* ((data->xmax - data->xmin) / WIDTH));
			y = data->ymin + (data->iter_y
					*((data->ymax - data->ymin) / HEIGHT));
			data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
			mandelbrot_set(x, y, data);
			data->iter_x++;
		}
		data->iter_y++;
		data->iter_x = 0;
	}
	return (1);
}
