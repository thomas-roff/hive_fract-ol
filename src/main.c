/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:31:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 11:36:34 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

t_fract	g_f;

int	main(int argc, char **argv)
{
	mlx_t		*window;

	(void)argv;
	if (argc > 1)
	{
		if (!parse_input(argv))
			input_prompt();
		init_window(&window, &g_f.image);
		mlx_loop_hook(window, commands, window);
		mlx_scroll_hook(window, scrolling, window);
		draw_image();
		mlx_loop(window);
		mlx_terminate(window);
	}
	return (EXIT_SUCCESS);
}

int	parse_input(char **argv)
{
	int	flag;

	flag = KO;
	if (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "Mandelbrot")
		|| !ft_strcmp(argv[1], "m") || !ft_strcmp(argv[1], "M"))
	{
		flag = OK;
		init_mandel();
	}
	else if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "Julia")
		|| !ft_strcmp(argv[1], "j") || !ft_strcmp(argv[1], "J"))
	{
		flag = OK;
		if (!argv[2] || !argv[3] || !ft_naf(argv[2]) || !ft_naf(argv[3]))
			return (KO);
		init_julia(argv);
	}
	return (flag);
}

void	init_window(mlx_t **window, mlx_image_t **image)
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

void	commands(void *param)
{
	mlx_t	*window;

	window = param;
	if (mlx_is_key_down(window, MLX_KEY_ESCAPE))
		mlx_close_window(window);
	if (mlx_is_key_down(window, MLX_KEY_UP))
		move_image('y', (0 - g_f.target_h / 100));
	if (mlx_is_key_down(window, MLX_KEY_DOWN))
		move_image('y', (g_f.target_h / 100));
	if (mlx_is_key_down(window, MLX_KEY_LEFT))
		move_image('x', (0 - g_f.target_h / 100));
	if (mlx_is_key_down(window, MLX_KEY_RIGHT))
		move_image('x', (g_f.target_h / 100));
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

void	draw_image(void)
{
	int	x;
	int	y;
	int	count;

	y = 1;
	count = 0;
	g_f.scale_x = g_f.target_w / g_f.window_w;
	g_f.scale_y = g_f.target_h / g_f.window_h;
	while (y < g_f.window_h)
	{
		x = 1;
		while (x < g_f.window_w)
		{
			if (g_f.type == 'm')
				draw_mandel(x, y, count);
			else if (g_f.type == 'j')
				draw_julia(x, y, count);
			x++;
		}
		y++;
	}
}
