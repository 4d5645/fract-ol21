#ifndef FRACTOL_H
#define FRACTOL_H

#include "miniLibX/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
# define SIZEX 600
# define SIZEY 600
# define ITERATION	120
#include <stdio.h> 

typedef struct s_data
{
	void	*mlx_win;
	void	*mlx;
	double	ymin;
	double	xmax;
	double	ymax;
	double	xmin;
	int		loopx;
	int		loopy;
	int		color;
	double	juliay;
	double	juliax;
}	t_data;

void	start_mandelbrot(t_data *mlx);
void	start_julia(t_data *mlx);

#endif