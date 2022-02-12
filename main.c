#include "fractol.h"


int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int	main(int argc, char **argv)
{
	t_data	data;

	
	if (argc >= 2)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot") )
			start_mandelbrot(&data);
		else if (!ft_strcmp(argv[1], "Julia"))
			start_julia(&data);
		else
		{
			printf(".::: The parameters is invalid! :::.\n");
		}
	}	
}
