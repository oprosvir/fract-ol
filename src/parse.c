/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:09:14 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/30 13:53:18 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip_space_sign(const char **str, int *is_neg)
{
	*is_neg = 1;
	while (ft_isspace((int)**str))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*is_neg = -1;
		(*str)++;
	}
}

static bool	check_digit_part(const char **str, bool *has_digit)
{
	while (ft_isdigit(**str))
	{
		*has_digit = true;
		(*str)++;
	}
	return (true);
}

static double	parse_integer(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

bool	ft_isdouble(const char *str)
{
	bool	has_decimal;
	bool	has_dig_before;
	bool	has_dig_after;
	int		sign;

	has_decimal = false;
	has_dig_before = false;
	has_dig_after = false;
	skip_space_sign(&str, &sign);
	if (!check_digit_part(&str, &has_dig_before))
		return (false);
	if (*str == '.')
	{
		has_decimal = true;
		str++;
		if (!check_digit_part(&str, &has_dig_after))
			return (false);
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
	divisor = 1.0;
	skip_space_sign(&str, &sign);
	result = parse_integer(&str);
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
