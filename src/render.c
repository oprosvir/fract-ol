/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:59:50 by oprosvir          #+#    #+#             */
/*   Updated: 2024/06/13 00:04:17 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int is_mandelbrot(t_complex complex)
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
        tmp = 2 * zr * zi + complex.imag;
        zr = zr * zr - zi * zi + complex.real;
        zi = tmp;
        i++;
    }
    return i;
}

static int is_julia(t_complex complex, t_fractol *app)
{
    double zr;
    double zi;
    double tmp;
    int i;

    zr = complex.real;
    zi = complex.imag;
    i = 0;
    while (zr * zr + zi * zi < 4 && i < MAX_ITERATIONS)
    {
        tmp = 2 * zr * zi + app->julia_cy;
        zr = zr * zr - zi * zi + app->julia_cx;
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
                iteration = is_mandelbrot(complex);
            else if (app->fractal_type == JULIA)
                iteration = is_julia(complex, app);
            put_pixel(app, x, y, get_color(app, iteration));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}
