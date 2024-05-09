/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:10 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/09 23:28:03 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void app_exit(t_fractol *app)
{
    if (app->win_ptr)
        mlx_destroy_window(app->mlx_ptr, app->win_ptr);
    if (app->mlx_ptr)
    {
        mlx_destroy_display(app->mlx_ptr);
        free(app->mlx_ptr);
        exit(0);
    }
}

int handle_keypress(int key, t_fractol *app)
{
    if (key == 65307)
        app_exit(app);
    return (0);
}
