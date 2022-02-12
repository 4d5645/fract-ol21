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
	data->xmin = -2;
	data->xmax = 2;
	data->ymin = -2;
	data->ymax = 2;
	data->color = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc >= 2)
	{
		initialize(&data);
		if (!ft_strcmp(argv[1], "Mandelbrot") )
			mandelbrot(&data);
		else if (!ft_strcmp(argv[1], "Julia"))
			julia(&data);
		else
			printf("Wrong name of fractal\n");
	}
	else
		printf("Wrong count of argumens\n");
}
