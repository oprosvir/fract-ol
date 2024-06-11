/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:10 by oprosvir          #+#    #+#             */
/*   Updated: 2024/06/12 00:31:16 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void zoom(t_fractol *app, double zoom_factor, int mouse_x, int mouse_y)
{
    double mouse_re;
    double mouse_im;

    mouse_re = app->min_r + (double)mouse_x / WIN_WIDTH * (app->max_r - app->min_r);
    mouse_im = app->min_i + (double)mouse_y / WIN_HEIGHT * (app->max_i - app->min_i);
    app->min_r = mouse_re + (app->min_r - mouse_re) * zoom_factor;
    app->max_r = mouse_re + (app->max_r - mouse_re) * zoom_factor;
    app->min_i = mouse_im + (app->min_i - mouse_im) * zoom_factor;
    app->max_i = mouse_im + (app->max_i - mouse_im) * zoom_factor;
}

int handle_mouse_events(int scroll_event, int x, int y, t_fractol *app)
{
    if (scroll_event == 4)
        zoom(app, 0.9, x, y);
    else if (scroll_event == 5)
        zoom(app, 1.1, x, y);
    fractal_render(app);
    return 0;
}

static void move(t_fractol *app, double distance, char direction)
{
    double center_r;
    double center_i;

    center_r = app->max_r - app->min_r;
    center_i = app->max_i - app->min_i;
    if (direction == 'R')
    {
        app->min_r += center_r * distance;
        app->max_r += center_r * distance;
    }
    else if (direction == 'L')
    {
        app->min_r -= center_r * distance;
        app->max_r -= center_r * distance;
    }
    else if (direction == 'D')
    {
        app->min_i += center_i * distance;
        app->max_i += center_i * distance;
    }
    else if (direction == 'U')
    {
        app->min_i -= center_i * distance;
        app->max_i -= center_i * distance;
    }
}

int handle_keypress(int keysym, t_fractol *app)
{
    if (keysym == XK_Escape)
        app_exit_success(app);
    else if (keysym == XK_Left)
        move(app, 0.1, 'L');
    else if (keysym == XK_Right)
        move(app, 0.1, 'R');
    else if (keysym == XK_Up)
        move(app, 0.1, 'U');
    else if (keysym == XK_Down)
        move(app, 0.1, 'D');
    fractal_render(app);
    return 0;
}
