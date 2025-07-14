/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:10 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 02:54:21 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
