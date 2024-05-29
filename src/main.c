/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:07:14 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/29 15:34:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractol *app, t_fractal_type type)
{
	app->fractal_type = type;
	app->zoom = 1.0;
	app->offset_x = -0.5;
	app->offset_y = 0.0;
	app->julia_cx = -0.718;
	app->julia_cy = -0.231;
	app->max_iterations = MAX_ITERATIONS;
}

static void	check_julia_params(t_fractol *app, const char *arg, bool is_x)
{
	double	value;

	value = ft_atof(arg);
	if (value > 2.0 || value < -2.0)
		invalid_arg();
	if (is_x)
		app->julia_cx = value;
	else
		app->julia_cy = value;
}

static void	init_arg(t_fractol *app, int argc, char *argv[])
{
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "M"))
			fractal_init(app, MANDELBROT);
		else if (!ft_strcmp(argv[1], "J"))
			fractal_init(app, JULIA);
		else
			invalid_arg();
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "J"))
	{
		if (!ft_isdouble(argv[2]) || !ft_isdouble(argv[3]))
            invalid_arg();
		fractal_init(app, JULIA);
		check_julia_params(app, argv[2], true);
		check_julia_params(app, argv[3], false);
	}
	else
		wrong_arg_num();
}

static void	init_window(t_fractol *app, char *title)
{
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
		allocation_error(app, "Error: Unable to initialize MLX");
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!app->win_ptr)
		allocation_error(app, "Error: Unable to create window");
	app->img_ptr = mlx_new_image(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!app->img_ptr)
		allocation_error(app, "Error: Unable to create image");
	app->img_data = mlx_get_data_addr(app->img_ptr, &app->bits_per_pixel,
			&app->line_size, &app->endian);
	if (!app->img_data)
		allocation_error(app, "Error: Unable to get image data address");
}

int	main(int argc, char *argv[])
{
	t_fractol	app;

	init_arg(&app, argc, argv);
	init_window(&app, WIN_TITLE);
	fractal_render(&app);
	mlx_mouse_hook(app.win_ptr, handle_mouse_events, &app);
	mlx_key_hook(app.win_ptr, handle_keypress, &app);
	mlx_hook(app.win_ptr, 17, 0, app_exit_success, &app);
	mlx_loop(app.mlx_ptr);
	return (EXIT_SUCCESS);
}
