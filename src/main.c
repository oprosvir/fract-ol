/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:07:14 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/07 00:16:32 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char *argv[])
{
    void    *mlx_ptr;
    void    *win_ptr;
    (void)argc;
    (void)argv;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 600, 300, "Test");
    mlx_pixel_put(mlx_ptr, win_ptr, 600/2, 300/2, 0xFFFFFF);
    mlx_loop(mlx_ptr);
    return (0);
}