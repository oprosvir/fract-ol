/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:54:00 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/19 20:32:59 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdbool.h>

# define WIN_TITLE "Fractol"
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITERATIONS 100

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}					t_fractal_type;

typedef struct s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				max_iterations;
	t_fractal_type	fractal_type;
	double			zoom;
	double			offset_x;
	double			offset_y;
	double			julia_cx;
	double			julia_cy;
}					t_fractol;

typedef struct s_atof
{
	double			result;
	double			fraction;
	int				sign;
	double			divisor;
	bool			has_decimal;
	bool			has_dig_before_dec;
	bool			has_dig_after_dec;
}					t_atof;

#endif