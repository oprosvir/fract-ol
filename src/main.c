/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:07:14 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/09 23:28:30 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractol *app, t_fractal_type type)
{
	app->fractal_type = type;
	app->julia_cx = -0.7; // 0.25 -0.55
	app->julia_cy = 0.27015;
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
	if (NULL == app->mlx_ptr)
		allocation_error();
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (NULL == app->win_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
		allocation_error();
	}
}

int	main(int argc, char *argv[])
{
	t_fractol	app;

	init_arg(&app, argc, argv);
	init_window(&app, argv[0]);
    mlx_key_hook(app.win_ptr, handle_keypress, &app);
	mlx_loop(app.mlx_ptr);
	return (EXIT_SUCCESS);
}
