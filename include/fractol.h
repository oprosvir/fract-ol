/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:49:52 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 03:11:39 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "defines.h"
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

void	fractal_init(t_fractol *app, t_fractal_type type);
void	wrong_arg_num(void);
void	invalid_arg(void);
void	allocation_error(t_fractol *app, const char *message);
void	fractal_render(t_fractol *app);
void	app_exit_code(t_fractol *app, int exit_code);
void	julia_shift(int x, int y, t_fractol *app);
bool	ft_isdouble(const char *str);
double	ft_atof(const char *str);
int		app_exit_success(t_fractol *app);
int		handle_keypress(int keysym, t_fractol *app);
int		get_color(t_fractol *app, int iteration);
int     mouse_press(int button, int x, int y, t_fractol *app);
int     mouse_release(int button, int x, int y, t_fractol *app);
int     mouse_move(int x, int y, t_fractol *app);

#endif
