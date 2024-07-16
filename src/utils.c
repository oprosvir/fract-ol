/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:22:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/07/16 17:07:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractol *app, t_fractal_type type)
{
	app->fractal_type = type;
	app->zoom = 1.0;
	app->min_r = -2.0;
	app->min_i = -2.0;
	app->max_r = app->min_r * -1 * WIN_WIDTH / WIN_HEIGHT;
	app->max_i = app->min_i * -1 * WIN_HEIGHT / WIN_WIDTH;
	app->julia_cx = -0.718;
	app->julia_cy = -0.231;
	app->iterations = 100;
	app->color_scheme = ELECTRIC;
}

void	julia_shift(int x, int y, t_fractol *app)
{
	app->julia_cx = app->min_r + (double)x * (app->max_r - app->min_r) \
		/ WIN_WIDTH;
	app->julia_cy = app->max_i + (double)y * (app->min_i - app->max_i) \
		/ WIN_HEIGHT;
	ft_printf("New Julia coordinates: cx = %f, cy = %f\n", app->julia_cx,
		app->julia_cy);
	fractal_render(app);
}

void	put_pixel(t_fractol *app, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		offset = (x * app->bits_per_pixel / 8) + (y * app->line_size);
		*(int *)(app->img_data + offset) = color;
	}
}

void	set_complex_values(t_fractol *app, int x, int y, t_complex *complex)
{
	double	scale_real;
	double	scale_imag;

	scale_real = (app->max_r - app->min_r) / WIN_WIDTH;
	scale_imag = (app->max_i - app->min_i) / WIN_HEIGHT;
	complex->real = app->min_r + x * scale_real;
	complex->imag = app->max_i - y * scale_imag;
}
