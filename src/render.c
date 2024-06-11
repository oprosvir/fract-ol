/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:59:50 by oprosvir          #+#    #+#             */
/*   Updated: 2024/06/12 01:01:50 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *app, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		offset = (x * app->bits_per_pixel / 8) + (y * app->line_size);
		*(int *)(app->img_data + offset) = color;
	}
}

static void set_complex_values(t_fractol *app, int x, int y, t_complex *complex)
{
    double scale_real;
    double scale_imag;

    scale_real = (app->max_r - app->min_r) / WIN_WIDTH;
    scale_imag = (app->max_i - app->min_i) / WIN_HEIGHT;

    complex->real = app->min_r + x * scale_real;
    complex->imag = app->min_i + y * scale_imag;
}

static int is_mandelbrot(double real, double imag)
{
    double zr;
    double zi;
    double tmp;
    int i;

    zr = 0;
    zi = 0;
    i = 0;
    while (zr * zr + zi * zi < 4 && i < MAX_ITERATIONS)
    {
        tmp = 2 * zr * zi + imag;
        zr = zr * zr - zi * zi + real;
        zi = tmp;
        i++;
    }
    return i;
}

static int is_julia(double real, double imag, double cx, double cy)
{
    double zr;
    double zi;
    double tmp;
    int i;

    zr = real;
    zi = imag;
    i = 0;
    while (zr * zr + zi * zi < 4 && i < MAX_ITERATIONS)
    {
        tmp = 2 * zr * zi + cy;
        zr = zr * zr - zi * zi + cx;
        zi = tmp;
        i++;
    }
    return i;
}

void fractal_render(t_fractol *app)
{
    int x;
    int y;
    t_complex complex;
    int iteration;

    y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            set_complex_values(app, x, y, &complex);
            if (app->fractal_type == MANDELBROT)
                iteration = is_mandelbrot(complex.real, complex.imag);
            else if (app->fractal_type == JULIA)
                iteration = is_julia(complex.real, complex.imag, app->julia_cx, app->julia_cy);
            put_pixel(app, x, y, get_color(iteration, app->max_iterations));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}
