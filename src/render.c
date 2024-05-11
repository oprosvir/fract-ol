/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:59:50 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/12 00:37:32 by oprosvir         ###   ########.fr       */
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

void	fractal_render(t_fractol *app)
{
	if (app->fractal_type == MANDELBROT)
		mandelbrot(app);
	else if (app->fractal_type == JULIA)
		julia(app);
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}
