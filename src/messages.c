/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:30:53 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 11:32:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_error(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
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
	ft_putendl_fd("\"mandelbrot\" or \"Mandelbrot\" as the", 1);
	ft_putendl_fd("first argument.", 1);
	ft_putendl_fd("e.g. \"./fract-ol m\"", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("JULIA", 1);
	ft_putendl_fd("For the Julia set pass \"j\", \"J\", \"julia\",", 1);
	ft_putendl_fd("or \"Julia\" as the first argument PLUS", 1);
	ft_putendl_fd("2 float values between -1.0 and 1.0 for", 1);
	ft_putendl_fd("for the constant in the order c-real,", 1);
	ft_putendl_fd("c-imaginary.", 1);
	ft_putendl_fd("e.g. \"./fract-ol julia 0.1 -0.7\"", 1);
	ft_putendl_fd("", 1);
	exit(EXIT_FAILURE);
}
