/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:59:50 by oprosvir          #+#    #+#             */
/*   Updated: 2024/06/12 17:24:01 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
            put_pixel(app, x, y, get_color(iteration));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}
