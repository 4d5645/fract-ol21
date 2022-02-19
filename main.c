/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:45:06 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:45:06 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	initialize(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->img = mlx_new_image(data, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->xmin = -2;
	data->xmax = 2;
	data->ymin = -2;
	data->ymax = 2;
	data->color = 0;
}

void	start_fractal(t_data *data, char flag)
{
	if (flag == 'm')
		mandelbrot(data);
	if (flag == 'j')
		julia(data);
}

/*
** Initialize the structure and determine which fractal is given as an argument.
** Draw fractal and read events.
*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc >= 2)
	{
		initialize(&data);
		if (!ft_strcmp(argv[1], "Mandelbrot"))
		{
			start_fractal(&data, 'm');
			mlx_hook(data.mlx_win, 17, 2, close_cross, NULL);
			mlx_key_hook(data.mlx_win, keys, &data);
			mlx_mouse_hook(data.mlx_win, zoom, (void *)&data);
			mlx_loop(data.mlx);
		}
		else if (!ft_strcmp(argv[1], "Julia"))
		{
			start_fractal(&data, 'j');
			mlx_hook(data.mlx_win, 17, 2, close_cross, NULL);
			mlx_key_hook(data.mlx_win, keys, &data);
			mlx_mouse_hook(data.mlx_win, zoom, (void *)&data);
			mlx_loop(data.mlx);
		}
		else
			printf("Wrong name of fractal\n");
	}
	else
		printf("Wrong count of argumens\n");
}
