/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:10 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 02:35:47 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_hook(t_fractol *app)
{
	if (app->fractal_type == JULIA && app->keys.mouse_left)
	{
		julia_shift(app->keys.mouse_x, app->keys.mouse_y, app);
		fractal_render(app);
	}
	return (0);
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


static void	move(t_fractol *app, char direction)
{
	double	range_r;
	double	range_i;

	range_r = app->max_r - app->min_r;
	range_i = app->max_i - app->min_i;
	if (direction == 'R')
	{
		app->min_r += range_r * MOVE_DISTANCE;
		app->max_r += range_r * MOVE_DISTANCE;
	}
	else if (direction == 'L')
	{
		app->min_r -= range_r * MOVE_DISTANCE;
		app->max_r -= range_r * MOVE_DISTANCE;
	}
	else if (direction == 'U')
	{
		app->min_i += range_i * MOVE_DISTANCE;
		app->max_i += range_i * MOVE_DISTANCE;
	}
	else if (direction == 'D')
	{
		app->min_i -= range_i * MOVE_DISTANCE;
		app->max_i -= range_i * MOVE_DISTANCE;
	}
}

int	handle_keypress(int keysym, t_fractol *app)
{
	if (keysym == XK_Escape)
		app_exit_success(app);
	else if (keysym == XK_Left)
		move(app, 'L');
	else if (keysym == XK_Right)
		move(app, 'R');
	else if (keysym == XK_Up)
		move(app, 'U');
	else if (keysym == XK_Down)
		move(app, 'D');
	else if (keysym == XK_plus || keysym == XK_KP_Add)
		app->iterations += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
	{
		if (app->iterations > 20)
			app->iterations -= 10;
	}	
	else if (keysym == XK_space)
		app->color_scheme = (app->color_scheme + 1) % 3;
	fractal_render(app);
	return (0);
}
