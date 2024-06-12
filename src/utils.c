/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:22:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/06/12 17:27:02 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: colour shifting
int get_color(int iteration) {
    if (iteration == MAX_ITERATIONS) {
        return 0x000000;  // Black color for points inside the fractal
    }

    // Generate a gradient color based on iteration count
    double t = (double)iteration / MAX_ITERATIONS;
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (r << 16) | (g << 8) | b;
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

void set_complex_values(t_fractol *app, int x, int y, t_complex *complex)
{
    double scale_real;
    double scale_imag;

    scale_real = (app->max_r - app->min_r) / WIN_WIDTH;
    scale_imag = (app->max_i - app->min_i) / WIN_HEIGHT;

    complex->real = app->min_r + x * scale_real;
    complex->imag = app->min_i + y * scale_imag;
}