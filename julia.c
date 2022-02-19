/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:46:23 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:46:23 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = x;
	yy = y;
	i = 1;
	while (i < ITERATION)
	{
		temp = xx;
		xx = (xx * xx - yy * yy) + 0.103 + mlx->juliax;
		yy = (2 * temp * yy) + 0.321 + mlx->juliay;
		if (xx * xx + yy * yy > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->mlx_win, mlx->loopx, mlx->loopy,
				(mlx->color) + 0x008DE3EC * i);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx -> mlx, mlx -> mlx_win, mlx->loopx, mlx->loopy, 0);
	return (0);
}

int	julia(t_data *data)
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
			x = data->xmin + (data->loopx
					* ((data->xmax - data->xmin) / WIDTH));
			y = data->ymax - (data->loopy
					* ((data->ymax - data->ymin) / HEIGHT));
			julia_set(x, y, data);
			data->loopx++;
		}
		data->loopy++;
		data->loopx = 0;
	}
	return (0);
}
