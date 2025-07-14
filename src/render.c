/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:59:50 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 03:11:23 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_mandelbrot(t_complex complex, t_fractol *app)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;

	i = 0;
	zr = 0.0;
	zi = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	while ((zr2 + zi2) < 4 && i < app->iterations)
	{
		zi = 2.0 * zr * zi + complex.imag;
		zr = zr2 - zi2 + complex.real;
		zr2 = zr * zr;
		zi2 = zi * zi;
		i++;
	}
	return (i);
}

static int	is_julia(t_complex complex, t_fractol *app)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;

	zr = complex.real;
	zi = complex.imag;
	i = 0;
	zr2 = zr * zr;
	zi2 = zi * zi;
	while ((zr2 + zi2) < 4 && i < app->iterations)
	{
		zi = 2.0 * zr * zi + app->julia_cy;
		zr = zr2 - zi2 + app->julia_cx;
		zr2 = zr * zr;
		zi2 = zi * zi;
		i++;
	}
	return (i);
}

static void	put_pixel(t_fractol *app, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		offset = (x * app->bits_per_pixel / 8) + (y * app->line_size);
		*(int *)(app->img_data + offset) = color;
	}
}

static void	set_complex_values(t_fractol *app, int x, int y, t_complex *complex)
{
	double	scale_real;
	double	scale_imag;

	scale_real = (app->max_r - app->min_r) / WIN_WIDTH;
	scale_imag = (app->max_i - app->min_i) / WIN_HEIGHT;
	complex->real = app->min_r + x * scale_real;
	complex->imag = app->max_i - y * scale_imag;
}

void	fractal_render(t_fractol *app)
{
	int			x;
	int			y;
	t_complex	complex;
	int			iteration;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			set_complex_values(app, x, y, &complex);
			if (app->fractal_type == MANDELBROT)
				iteration = is_mandelbrot(complex, app);
			else if (app->fractal_type == JULIA)
				iteration = is_julia(complex, app);
			put_pixel(app, x, y, get_color(app, iteration));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}
