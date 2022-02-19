/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:50:10 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:50:10 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_cross(void)
{
	exit(0);
	return (0);
}

void	move(int key_code, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin);
	dy = (mlx->ymax - mlx->ymin);
	if (key_code == 123 || key_code == 124)
	{
		if (key_code == 123)
			dx *= -1;
		mlx->xmin += dx / 7.5;
		mlx->xmax += dx / 7.5;
	}
	if (key_code == 126 || key_code == 125)
	{
		if (key_code == 125)
			dy *= -1;
		mlx->ymin += dy / 7.5;
		mlx->ymax += dy / 7.5;
	}
}

int	keys(int keycode, t_data *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124
		|| keycode == 126 || keycode == 125)
		move(keycode, mlx);
	if (keycode == 8 || keycode == 99)
		mlx->color += 0x00321123;
	if (keycode == 1 || keycode == 115)
		mlx->juliay += 0.2;
	if (keycode == 13 || keycode == 119)
		mlx->juliay -= 0.2;
	if (keycode == 0 || keycode == 97)
		mlx->juliax -= 0.2;
	if (keycode == 2 || keycode == 100)
		mlx->juliax += 0.2;
	start_fractal(mlx, 'm');
	return (0);
}

int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin) / WIDTH;
	dy = (mlx->ymax - mlx->ymin) / HEIGHT;
	if (keycode == 5)
	{
		mlx->xmin = (mlx->xmin + ((dx * x) * 0.3));
		mlx->xmax = (mlx->xmax - ((dx * (WIDTH - x)) * 0.3));
		mlx->ymax = (mlx->ymax - ((dy * y) * 0.3));
		mlx->ymin = (mlx->ymin + ((dy * (HEIGHT - y)) * 0.3));
	}
	if (keycode == 4)
	{
		mlx->xmin = (mlx->xmin - ((dx * x) * 0.3));
		mlx->xmax = (mlx->xmax + ((dx * (WIDTH - x)) * 0.3));
		mlx->ymax = (mlx->ymax + ((dy * y) * 0.3));
		mlx->ymin = (mlx->ymin - ((dy * (HEIGHT - y)) * 0.3));
	}
	start_fractal(mlx, 'm');
	return (0);
}
