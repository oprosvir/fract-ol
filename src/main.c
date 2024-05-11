/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:07:14 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/12 01:27:12 by oprosvir         ###   ########.fr       */
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
	app->max_iterations = 100;
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
		fractal_init(app, JULIA);
		// TODO нет ли тут проблем. я назначаю по умолч, а потом меня на пользов
		if (!ft_isdouble(argv[2]) || !ft_isdouble(argv[3]))
			invalid_arg();
		app->julia_cx = ft_atof(argv[2]);
		app->julia_cy = ft_atof(argv[3]);
		if (app->julia_cx > 2.0 || app->julia_cx < -2.0 || app->julia_cy > 2.0
			|| app->julia_cy < -2.0)
			invalid_arg();
	}
	else
		wrong_arg_num();
}

static void	init_window(t_fractol *app, char *title)
{
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
		allocation_error();
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!app->win_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
		allocation_error();
	}
	app->img_ptr = mlx_new_image(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!app->img_ptr)
	{
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
		allocation_error();
	}
	app->img_data = mlx_get_data_addr(app->img_ptr, &app->bits_per_pixel,
			&app->line_size, &app->endian);
}

int	main(int argc, char *argv[])
{
	t_fractol	app;

	init_arg(&app, argc, argv);
	init_window(&app, WIN_TITLE);
	fractal_render(&app);
	mlx_mouse_hook(app.win_ptr, handle_mouse_events, &app);
	mlx_key_hook(app.win_ptr, handle_keypress, &app);
	mlx_hook(app.win_ptr, 17, 0, app_exit, &app);
	mlx_loop(app.mlx_ptr);
	return (EXIT_SUCCESS);
}
