/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:57:56 by ravazque          #+#    #+#             */
/*   Updated: 2025/09/07 18:17:56 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	is_julia(t_fractal *fractal, int *flag, int argc, char **argv)
{
	if (argc == 4)
	{
		fractal->julia_x = atodbl(argv[2], flag);
		fractal->julia_y = atodbl(argv[3], flag);
	}
	else
	{
		fractal->julia_x = 0;
		fractal->julia_y = 0;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	int			flag;

	flag = 0;
	if ((argc == 2 && !ft_strncmp(argv[1], ARG_MAN, 10)) || (argc == 4
			&& !ft_strncmp(argv[1], ARG_JUL, 5)))
	{
		fractal.name = argv[1];
		is_julia(&fractal, &flag, argc, argv);
		if (flag != 0)
			return (ft_putstr_fd("Insert appropriate values\n", 2), 2);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		return (ft_putstr_fd(ARG_ERR1, 2), ft_putstr_fd(ARG_ERR2, 2), 2);
	return (0);
}
