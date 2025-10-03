/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:31:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:43:49 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

int	main(int argc, char **argv)
{
	t_fract	f;

	if (argc > 1)
	{
		if (!parse_input(&f, argc, argv))
			input_prompt();
		if (f.type == 'm')
			init_mandel(&f);
		else if (f.type == 'j')
			init_julia(&f, argv);
		init_window(&f.window, &f.image);
		mlx_loop_hook(f.window, commands, &f);
		mlx_scroll_hook(f.window, scrolling, &f);
		draw_image(f);
		mlx_loop(f.window);
		mlx_close_window(f.window);
		mlx_terminate(f.window);
	}
	else
		input_prompt();
	return (EXIT_SUCCESS);
}

void	commands(void *params)
{
	t_fract	*f;

	f = (t_fract *)params;
	if (mlx_is_key_down(f->window, MLX_KEY_ESCAPE))
		mlx_close_window(f->window);
	if (mlx_is_key_down(f->window, MLX_KEY_UP))
		move_image(f, 'y', (0 - f->target_h / 100));
	if (mlx_is_key_down(f->window, MLX_KEY_DOWN))
		move_image(f, 'y', (f->target_h / 100));
	if (mlx_is_key_down(f->window, MLX_KEY_LEFT))
		move_image(f, 'x', (0 - f->target_h / 100));
	if (mlx_is_key_down(f->window, MLX_KEY_RIGHT))
		move_image(f, 'x', (f->target_h / 100));
	if (mlx_is_key_down(f->window, MLX_KEY_C))
		color_change(f, 'c');
	if (mlx_is_key_down(f->window, MLX_KEY_COMMA))
		color_change(f, ',');
	if (mlx_is_key_down(f->window, MLX_KEY_PERIOD))
		color_change(f, '.');
	if (mlx_is_key_down(f->window, MLX_KEY_LEFT_BRACKET))
		rotate_julia(f, 'l');
	if (mlx_is_key_down(f->window, MLX_KEY_RIGHT_BRACKET))
		rotate_julia(f, 'r');
	if (f->redraw == TRUE)
		draw_image(*f);
}

void	scrolling(double xdelta, double ydelta, void *params)
{
	t_fract	*f;
	double	old_centerx;
	double	old_centery;

	(void)xdelta;
	f = (t_fract *)params;
	old_centerx = f->target_x + f->target_w / 2;
	old_centery = f->target_y + f->target_h / 2;
	if (ydelta > 0)
		zoom_image(f, 0.9);
	else if (ydelta < 0)
		zoom_image(f, 1.1111111);
	else
		return ;
	if (f->target_w > 9)
		f->target_w = 9;
	if (f->target_h > 9)
		f->target_h = 9;
	f->target_x = old_centerx - (f->target_w / 2);
	f->target_y = old_centery - (f->target_h / 2);
	draw_image(*f);
}

void	draw_image(t_fract f)
{
	int	x;
	int	y;
	int	count;

	y = 1;
	count = 0;
	f.scale_x = f.target_w / (float)f.window_w;
	f.scale_y = f.target_h / (float)f.window_h;
	while (y < f.window_h)
	{
		x = 1;
		while (x < f.window_w)
		{
			if (f.type == 'm')
				draw_mandel(f, f.image, x, y);
			else if (f.type == 'j')
				draw_julia(f, f.image, x, y);
			x++;
		}
		y++;
	}
	f.redraw = FALSE;
}
