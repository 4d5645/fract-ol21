/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:47:29 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:47:29 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
# define FRACTOL_H

# include "miniLibX/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define WIDTH 800
# define HEIGHT 800
# define ITERATION	120
# include <stdio.h> 

typedef struct s_data
{
	void	*mlx_win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	ymin;
	double	xmax;
	double	ymax;
	double	xmin;
	int		iter_x;
	int		iter_y;
	int		color;
	double	change_y;
	double	change_x;
}	t_data;

int		mandelbrot(t_data *mlx);
int		julia(t_data *mlx);
int		close_cross(void);
void	move(int keycode, t_data *mlx);
int		keys(int keycode, t_data *mlx);
void	start_fractal(t_data *data, char flag);
int	zoom(int keycode, int x, int y, t_data *mlx);

#endif
