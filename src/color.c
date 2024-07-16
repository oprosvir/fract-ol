/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:27:09 by oprosvir          #+#    #+#             */
/*   Updated: 2024/07/16 10:14:26 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color_electric(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	get_color_neon(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * (1 - t) * t * t);
	g = (int)(255 * sqrt(t));
	b = (int)(255 * t * (1 - t));
	return ((r << 16) | (g << 8) | b);
}

static int	get_color_psychedelic(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 + sin(0.16 * t * 360 + 4)) * 127.5);
	g = (int)((1 + sin(0.16 * t * 360 + 2)) * 127.5);
	b = (int)((1 + sin(0.16 * t * 360 + 0)) * 127.5);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(t_fractol *app, int iteration)
{
	double	t;

	if (iteration == app->iterations)
		return (0x000000);
	t = (double)iteration / app->iterations;
	if (app->color_scheme == ELECTRIC)
		return (get_color_electric(t));
	else if (app->color_scheme == NEON)
		return (get_color_neon(t));
	else if (app->color_scheme == PSYCHEDELIC)
		return (get_color_psychedelic(t));
	else
		return (0x000000);
}
