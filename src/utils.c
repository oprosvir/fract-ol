/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:09:14 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/29 15:31:26 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	app_exit_code(t_fractol *app, int exit_code)
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

bool	ft_isdouble(const char *str)
{
	bool	has_decimal;
	bool	has_dig_before;
	bool	has_dig_after;

	has_decimal = false;
	has_dig_before = false;
	has_dig_after = false;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit((unsigned char)*str))
		{
			if (has_decimal)
				has_dig_after = true;
			else
				has_dig_before = true;
		}
		else if (*str == '.')
		{
			if (has_decimal)
				return (false);
			has_decimal = true;
		}
		else
			return (false);
		str++;
	}
	return (has_decimal && has_dig_before && has_dig_after);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	double	divisor;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	divisor = 1.0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction = fraction * 10 + (*str - '0');
			divisor *= 10;
			str++;
		}
	}
	result += fraction / divisor;
	return (sign * result);
}
