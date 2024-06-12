/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:49:52 by oprosvir          #+#    #+#             */
/*   Updated: 2024/06/12 17:23:39 by oprosvir         ###   ########.fr       */
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
# include <stdbool.h>

void	wrong_arg_num(void);
void	invalid_arg(void);
void	allocation_error(t_fractol *app, const char *message);
void	put_pixel(t_fractol *app, int x, int y, int color);
void	fractal_render(t_fractol *app);
void	app_exit_code(t_fractol *app, int exit_code);
void    set_complex_values(t_fractol *app, int x, int y, t_complex *complex);
bool	ft_isdouble(const char *str);
double	ft_atof(const char *str);
int		app_exit_success(t_fractol *app);
int		handle_keypress(int keysym, t_fractol *app);
int     get_color(int iteration);
int		handle_mouse_events(int button, int x, int y, t_fractol *app);

#endif
