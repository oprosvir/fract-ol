/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:48:50 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 02:50:39 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_shift(int x, int y, t_fractol *app)
{
	app->julia_cx = app->min_r + (double)x * (app->max_r - app->min_r) \
		/ WIN_WIDTH;
	app->julia_cy = app->max_i + (double)y * (app->min_i - app->max_i) \
		/ WIN_HEIGHT;
	// TODO: fix output format, use mlx_string_put
	ft_printf("New Julia coordinates: cx = %f, cy = %f\n", app->julia_cx,
		app->julia_cy);
}

static void	zoom(t_fractol *app, double zoom_factor, int mouse_x, int mouse_y)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = app->min_r + (double)mouse_x / WIN_WIDTH * (app->max_r \
		- app->min_r);
	mouse_im = app->max_i - (double)mouse_y / WIN_HEIGHT * (app->max_i \
		- app->min_i);
	app->min_r = mouse_re + (app->min_r - mouse_re) * zoom_factor;
	app->max_r = mouse_re + (app->max_r - mouse_re) * zoom_factor;
	app->min_i = mouse_im + (app->min_i - mouse_im) * zoom_factor;
	app->max_i = mouse_im + (app->max_i - mouse_im) * zoom_factor;
	fractal_render(app);
}

int	mouse_press(int button, int x, int y, t_fractol *app)
{
	if (button == MOUSE_SCROLL_UP)
		zoom(app, 0.9, x, y);
	else if (button == MOUSE_SCROLL_DOWN)
		zoom(app, 1.1, x, y);
	else if (button == MOUSE_LEFT_BUTTON)
	{
		app->keys.mouse_left = 1;
		app->keys.mouse_x = x;
		app->keys.mouse_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_fractol *app)
{
	if (button == MOUSE_LEFT_BUTTON)
		app->keys.mouse_left = 0;
	(void)x;
	(void)y;
	return (0);
}

int mouse_move(int x, int y, t_fractol *app)
{
	if (app->fractal_type == JULIA && app->keys.mouse_left)
	{
		app->keys.mouse_x = x;
		app->keys.mouse_y = y;
	}
	return (0);
}
