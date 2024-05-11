/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:49:52 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/12 00:21:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "defines.h"
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

void	wrong_arg_num(void);
void	invalid_arg(void);
void	allocation_error(void);
double	ft_atof(const char *str);
int		app_exit(t_fractol *app);
int		handle_keypress(int keysym, t_fractol *app);
int		get_color(int iteration, int max_iterations);
void	put_pixel(t_fractol *app, int x, int y, int color);
void	mandelbrot(t_fractol *app);
void	fractal_render(t_fractol *app);
int		handle_mouse_events(int button, int x, int y, t_fractol *app);
void	julia(t_fractol *app);

#endif
