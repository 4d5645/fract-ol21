#include "fractol.h"

int	close_esc(void)
{
	exit(0);
	return (0);
}


// void	move(int keycode, t_data *mlx)
// {
// 	float	dx;
// 	float	dy;

// 	dx = (mlx->xmax - mlx->xmin);
// 	dy = (mlx->ymax - mlx->ymin);
// 	if (keycode == 53 || keycode == 65307) 
// 		exit(0);
// 	if (keycode == 123 || keycode == 124 || keycode == 65363 || keycode == 65361)
// 	{
// 		if (keycode == 123 || keycode == 65361)
// 			dx *= -1;
// 		mlx->xmin += dx / 7.5;
// 		mlx->xmax += dx / 7.5;
// 	}
// 	if (keycode == 126 || keycode == 125 || keycode == 65364 || keycode == 65362)
// 	{
// 		if (keycode == 125 || keycode == 65364)
// 			dy *= -1;
// 		mlx->ymin += dy / 7.5;
// 		mlx->ymax += dy / 7.5;
// 	}
// }

// int	keys(int keycode, t_data *mlx)
// { 
// 	if (keycode == 53 || keycode == 123 || keycode == 124
// 		|| keycode == 126 || keycode == 125 || keycode == 65307 ||
//         keycode == 65363 || keycode == 65361 || keycode == 65364 || keycode == 65362)
// 		move(keycode, mlx);
// 	if (keycode == 8 || keycode == 99)
// 		mlx->color += 0x00321123;
// 	if (keycode == 1 || keycode == 115)
// 		mlx->juliay += 0.2;
// 	if (keycode == 13 || keycode == 119)
// 		mlx->juliay -= 0.2;
// 	if (keycode == 0 || keycode == 97)
// 		mlx->juliax -= 0.2;
// 	if (keycode == 2 || keycode == 100)
// 		mlx->juliax += 0.2;
// 	ft_run(mlx, 1);
// 	return (0);
// }

// int	zoom(int keycode, int x, int y, t_data *mlx)
// {
// 	float	dx;
// 	float	dy;

// 	dx = (mlx->xmax - mlx->xmin) / SIZEX;
// 	dy = (mlx->ymax - mlx->ymin) / SIZEY;
// 	if (keycode == 5)
// 	{
// 		mlx->xmin = (mlx->xmin + ((dx * x) * 0.5));
// 		mlx->xmax = (mlx->xmax - ((dx * (SIZEX - x)) * 0.5));
// 		mlx->ymax = (mlx->ymax - ((dy * y) * 0.5));
// 		mlx->ymin = (mlx->ymin + ((dy * (SIZEY - y)) * 0.5));
// 	}
// 	if (keycode == 4)
// 	{
// 		mlx->xmin = (mlx->xmin - ((dx * x) * 0.5));
// 		mlx->xmax = (mlx->xmax + ((dx * (SIZEX - x)) * 0.5));
// 		mlx->ymax = (mlx->ymax + ((dy * y) * 0.5));
// 		mlx->ymin = (mlx->ymin - ((dy * (SIZEY - y)) * 0.5));
// 	}
// 	ft_run(mlx, 1);
// 	return (0);
// }
