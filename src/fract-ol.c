/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:31:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/16 14:45:23 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static mlx_image_t *image;

static void ft_error(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	commands(void *param)
{
	mlx_t	*window;

	window = param;
	if (mlx_is_key_down(window, MLX_KEY_ESCAPE))
		mlx_close_window(window);
}

static void	navigation(void *param)
{
	mlx_t	*window;

	window = param;
	if (mlx_is_key_down(window, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(window, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(window, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(window, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

void draw_rectangle(mlx_image_t* image, int x, int y, int width, int height, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_put_pixel(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	init_window(mlx_t **window, mlx_image_t **image)
{
	*window = mlx_init(WIDTH, HEIGHT, "Fract-ol", TRUE);
	if (!*window)
		ft_error();
	*image = mlx_new_image(*window, 128, 128);
	if (!*image || mlx_image_to_window(*window, *image, 0, 0) < 0)
	{
		mlx_close_window(*window);
		ft_error();
	}
}

int	main(int argc, char **argv)
{
	mlx_t		*window;
	uint32_t	red;

	(void)argv;
	if (argc > 1)
	{
		init_window(&window, &image);
		mlx_put_pixel(image, 0, 0, 0xFF0000FF);
		mlx_loop_hook(window, navigation, window);
		mlx_loop_hook(window, commands, window);
		red = 0xFF0000FF;
		draw_rectangle(image, 0, 0, 128, 128, red);
		// mlx_scroll_hook(window, ft_zoom, window);
		mlx_loop(window);
		mlx_terminate(window);
	}
	return (EXIT_SUCCESS);
}
