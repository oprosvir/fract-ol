/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:36:29 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/08 23:16:55 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Printing the help message with ANSI escape codes for colors and styles
void display_help() 
{
    ft_printf("************************************************************\n");
    ft_printf("*                 \033[1;36mWelcome to Fract'ol!\033[0m                     *\n");
    ft_printf("************************************************************\n");
    ft_printf("* \033[1;38;5;142mFractals:\033[0m                                                *\n");
    ft_printf("*   M - Mandelbrot                                         *\n");
    ft_printf("*   J - Julia                                              *\n");
    ft_printf("* \033[38;5;98mUsage example:\t./fractol M\033[0m                        *\n");
    ft_printf("*                       \033[38;5;98m./fractol J\033[0m                        *\n");
    ft_printf("*                                                          *\n");
    ft_printf("* For Julia, you may specify initial values between        *\n");
    ft_printf("* -2.0 and 2.0, ensuring they include a decimal point \033[0m     *\n");
    ft_printf("* \033[38;5;98mUsage example:\t./fractol J 0.25 -0.55\033[0m             *\n");
    ft_printf("*                                                          *\n");
    ft_printf("* \033[1;38;5;142mControls:\033[0m                                                *\n");
    ft_printf("*   - \033[38;5;43mMovement:\033[0m Arrow keys (left, right, up, down)         *\n");
    ft_printf("*   - \033[38;5;43mZoom:\033[0m Mouse wheel up / down                          *\n");
    ft_printf("*   - \033[38;5;43mSwitch fractal:\033[0m 'M' for Mandelbrot, 'J' for Julia    *\n");
    ft_printf("*   - \033[38;5;43mAdjust Julia parameters:\033[0m Click and drag with mouse   *\n");
    ft_printf("*   - \033[38;5;43mExit:\033[0m ESC                                            *\n");
    ft_printf("************************************************************\033[0m\n");
}

void wrong_arg_num()
{
    ft_printf("\033[1;31mError: Invalid number of arguments.\033[0m\n");
    display_help();
    exit(EXIT_FAILURE);
}

void invalid_arg() 
{
    ft_printf("\033[1;31mError: Invalid argument.\033[0m\n");
    display_help();
    exit(EXIT_FAILURE);
}

void allocation_error()
{
    perror("Error: Unable to allocate resources");
    exit(EXIT_FAILURE);
}
