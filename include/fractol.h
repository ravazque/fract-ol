/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:28 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/10 18:46:24 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../src/aux_libft/include/libft.h"

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

# define ARG_MAN "mandelbrot"
# define ARG_JUL "julia"
# define ARG_ERR1 "Please enter:\n\t./fractol mandelbrot\n"
# define ARG_ERR2 "\t./fractol julia <value_1> <value_2>\n"

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define BROWN 0xA52A2A

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bbp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map1(double new_min, double old_min, double old_max);
double		map2(double uns_num, double n_min, double n_max, double o_min);
double		atodbl(const char *s, int *flag);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysys, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
