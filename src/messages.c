/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:30:53 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 12:20:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_error(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	input_helper(void)
{
	ft_putendl_fd("========================================", 1);
	ft_putendl_fd("|         THOMASROFF FRACT-OL          |", 1);
	ft_putendl_fd("========================================", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("NAVIGATION", 1);
	ft_putendl_fd(" - Mouse scroll wheel: zoom in and out.", 1);
	ft_putendl_fd(" - Arrow keys: move up, down, left", 1);
	ft_putendl_fd("   and right.", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("COLOUR", 1);
	ft_putendl_fd(" - \"c\": change colour palette (cycles", 1);
	ft_putendl_fd("   through colour wheel.", 1);
	ft_putendl_fd(" - \",\" & \".\" increase and decrease", 1);
	ft_putendl_fd("   range of colours used on color wheel.", 1);
	ft_putendl_fd(" - \"[\" & \"]\" rotate Julia set (rotates", 1);
	ft_putendl_fd("   c-real/c-imaginary around zero).", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("EXIT", 1);
	ft_putendl_fd(" - \"[ESC]\" to close.", 1);
	ft_putendl_fd("", 1);
	exit(EXIT_FAILURE);
}

void	input_prompt(void)
{
	ft_putendl_fd("========================================", 1);
	ft_putendl_fd("|         THOMASROFF FRACT-OL          |", 1);
	ft_putendl_fd("========================================", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Please specify which fractal set you", 1);
	ft_putendl_fd("wish to visualise.", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("MANDELBROT", 1);
	ft_putendl_fd("For the Mandelbrot set pass \"m\", \"M\",", 1);
	ft_putendl_fd("\"mandelbrot\" or \"Mandelbrot\" as an", 1);
	ft_putendl_fd("argument.", 1);
	ft_putendl_fd("e.g. \"./fractol m\"", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("JULIA", 1);
	ft_putendl_fd("For the Julia set pass \"j\", \"J\", \"julia\",", 1);
	ft_putendl_fd("or \"Julia\" as the first argument PLUS", 1);
	ft_putendl_fd("2 float values (best results between", 1);
	ft_putendl_fd("-1.0 and 1.0) for the constant in the", 1);
	ft_putendl_fd("order c-real, c-imaginary.", 1);
	ft_putendl_fd("e.g. \"./fractol julia 0.1 -0.7\"", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("For help with controls use the argument:", 1);
	ft_putendl_fd("\"-help\". e.g. \"./fractol -help\"", 1);
	ft_putendl_fd("", 1);
	exit(EXIT_FAILURE);
}
