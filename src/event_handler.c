/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:10 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/12 01:34:07 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	app_exit(t_fractol *app)
{
	if (app->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img_ptr);
	if (app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	if (app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
		app->mlx_ptr = NULL;
	}
	exit(EXIT_SUCCESS);
}

void	handle_zoom(t_fractol *app, double zoom_factor, int x, int y)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (double)(x - WIN_WIDTH / 2) / (WIN_WIDTH * app->zoom);
	mouse_y = (double)(y - WIN_HEIGHT / 2) / (WIN_HEIGHT * app->zoom);
	app->zoom *= zoom_factor;
	app->offset_x += mouse_x * (1 - zoom_factor);
	app->offset_y += mouse_y * (1 - zoom_factor);
}

int	handle_mouse_events(int scroll_event, int x, int y, t_fractol *app)
{
	if (scroll_event == 4)
		handle_zoom(app, 0.9, x, y);
	if (scroll_event == 5)
		handle_zoom(app, 1.1, x, y);
	fractal_render(app);
	return (0);
}

// TODO: arrow keys
int	handle_keypress(int keysym, t_fractol *app)
{
	if (keysym == XK_Escape)
		app_exit(app);
	if (keysym == XK_Left)
	{ /* смещение влево */
	}
	if (keysym == XK_Right)
	{ /* вправо */
	}
	if (keysym == XK_Up)
	{ /* вверх */
	}
	if (keysym == XK_Down)
	{ /* вниз */
	}
	return (0);
}
