/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:31:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/30 13:11:36 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

t_fract	f;

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
	if (mlx_is_key_down(window, MLX_KEY_UP))
		move_image('y', (0 - f.target_h / 100));
	if (mlx_is_key_down(window, MLX_KEY_DOWN))
		move_image('y', (f.target_h / 100));
	if (mlx_is_key_down(window, MLX_KEY_LEFT))
		move_image('x', (0 - f.target_h / 100));
	if (mlx_is_key_down(window, MLX_KEY_RIGHT))
		move_image('x', (f.target_h / 100));
	if (mlx_is_key_down(window, MLX_KEY_C))
		color_change('c');
	if (mlx_is_key_down(window, MLX_KEY_COMMA))
		color_change(',');
	if (mlx_is_key_down(window, MLX_KEY_PERIOD))
		color_change('.');
	if (mlx_is_key_down(window, MLX_KEY_LEFT_BRACKET))
		rotate_julia('l');
	if (mlx_is_key_down(window, MLX_KEY_RIGHT_BRACKET))
		rotate_julia('r');
}

static void	init_window(mlx_t **window, mlx_image_t **image)
{
	*window = mlx_init(WIDTH, HEIGHT, "Fract-ol", TRUE);
	if (!*window)
		ft_error();
	*image = mlx_new_image(*window, WIDTH, HEIGHT);
	if (!*image || mlx_image_to_window(*window, *image, 0, 0) < 0)
	{
		mlx_close_window(*window);
		ft_error();
	}
}

static void	parse_args(char **argv)
{
	f.julia_cx = ft_atof(argv[2]);
	f.julia_cy = ft_atof(argv[3]);
}

int	main(int argc, char **argv)
{
	mlx_t		*window;

	(void)argv;
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			init_mandel();
		if (!ft_strcmp(argv[1], "julia"))
		{
			parse_args(argv);
			init_julia();
		}
		init_window(&window, &f.image);
		mlx_loop_hook(window, commands, window);
		mlx_scroll_hook(window, scrolling, window);
		draw_image();
		mlx_loop(window);
		mlx_terminate(window);
	}
	return (EXIT_SUCCESS);
}
