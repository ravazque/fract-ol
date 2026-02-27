/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:54:38 by ravazque          #+#    #+#             */
/*   Updated: 2025/09/07 18:14:13 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysys, t_fractal *fractal)
{
	if (keysys == XK_Escape)
		close_handler(fractal);
	else if (keysys == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysys == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysys == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysys == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysys == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysys == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}
