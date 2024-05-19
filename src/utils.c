/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:09:14 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/19 20:44:39 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	app_exit_code(t_fractol *app, int exit_code)
{
	if (app->img_ptr)
		mlx_destroy_image(app->mlx_ptr, app->img_ptr);
	if (app->win_ptr)
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	if (app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
		app->mlx_ptr = NULL;
	}
	exit(exit_code);
}

int	app_exit_success(t_fractol *app)
{
	app_exit_code(app, EXIT_SUCCESS);
	return (0);
}

static const char	*skip_space_sign(const char *str, t_atof *atof_data)
{
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '-')
	{
		atof_data->sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

static const char	*parse_parts(const char *str, t_atof *atof_data)
{
	while (ft_isdigit((unsigned char)*str))
	{
		atof_data->has_dig_before_dec = true;
		atof_data->result = atof_data->result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		atof_data->has_decimal = true;
		str++;
		while (ft_isdigit((unsigned char)*str))
		{
			atof_data->has_dig_after_dec = true;
			atof_data->fraction = atof_data->fraction * 10 + (*str - '0');
			atof_data->divisor *= 10;
			str++;
		}
	}
	return (str);
}

double	ft_atof(const char *str)
{
	t_atof	atof_data;

	atof_data.result = 0.0;
	atof_data.fraction = 0.0;
	atof_data.sign = 1;
	atof_data.divisor = 1.0;
	atof_data.has_decimal = false;
	atof_data.has_dig_before_dec = false;
	atof_data.has_dig_after_dec = false;
	str = skip_space_sign(str, &atof_data);
	str = parse_parts(str, &atof_data);
	if (!atof_data.has_decimal || !atof_data.has_dig_before_dec
		|| !atof_data.has_dig_after_dec || *str != '\0')
	{
		return (-42.0);
	}
	atof_data.result += atof_data.fraction / atof_data.divisor;
	return (atof_data.sign * atof_data.result);
}
