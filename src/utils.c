/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:22:15 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 03:11:05 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractol *app, t_fractal_type type)
{
	app->fractal_type = type;
	app->zoom = 1.0;
	app->min_r = -2.0;
	app->min_i = -2.0;
	app->max_r = app->min_r * -1 * WIN_WIDTH / WIN_HEIGHT;
	app->max_i = app->min_i * -1 * WIN_HEIGHT / WIN_WIDTH;
	app->julia_cx = -0.718;
	app->julia_cy = -0.231;
	app->iterations = 100;
	app->color_scheme = ELECTRIC;
	app->keys.mouse_left = 0;
	app->keys.mouse_x = 0;
	app->keys.mouse_y = 0;
}
