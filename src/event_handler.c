/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:10 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/11 01:56:43 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int app_exit(t_fractol *app)
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

int handle_keypress(int keysym, t_fractol *app)
{
    if (keysym == XK_Escape)
        app_exit(app);
    if (keysym == XK_Left) { /* смещение влево */ }
    if (keysym == XK_Right) { /* вправо */ }
    if (keysym== XK_Up) { /* вверх */ }
    if (keysym == XK_Down) { /* вниз */ }
    return (0);
}
