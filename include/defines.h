/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:54:00 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 01:13:04 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_TITLE "Fractol"
# define WIN_WIDTH 900
# define WIN_HEIGHT 900

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_LEFT_BUTTON 1

# define MOVE_DISTANCE 0.1

typedef struct s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef enum e_color_scheme
{
	ELECTRIC,
	NEON,
	PSYCHEDELIC
}					t_color_scheme;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}					t_fractal_type;

typedef struct s_keys
{
	int	mouse_left;
	int	mouse_x;
	int	mouse_y;
}					t_keys;

typedef struct s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				iterations;
	t_fractal_type	fractal_type;
	t_color_scheme	color_scheme;
	double			zoom;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			julia_cx;
	double			julia_cy;
	t_keys			keys;
}					t_fractol;

#endif