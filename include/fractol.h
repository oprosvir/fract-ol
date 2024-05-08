/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:49:52 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/08 23:41:43 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "defines.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

void	wrong_arg_num(void);
void	invalid_arg(void);
void	allocation_error(void);
double	ft_atof(const char *str);

#endif
