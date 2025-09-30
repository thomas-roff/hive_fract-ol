/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:31:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/22 13:30:41 by thblack-         ###   ########.fr       */
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
	{
		f.image->instances[0].y -= 5;
		// f.sq_y -= 5;
	}
	if (mlx_is_key_down(window, MLX_KEY_DOWN))
	{
		f.image->instances[0].y += 5;
		// f.sq_y += 5;
	}
	if (mlx_is_key_down(window, MLX_KEY_LEFT))
	{
		f.image->instances[0].x -= 5;
		// f.sq_x -= 5;
	}
	if (mlx_is_key_down(window, MLX_KEY_RIGHT))
	{
		f.image->instances[0].x += 5;
		// f.sq_x += 5;
	}
}

static void	clear_image(mlx_image_t *image)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			mlx_put_pixel(image, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void draw_rectangle(mlx_image_t *image, int width, int height, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	clear_image(image);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_put_pixel(image, j, i, color);
			j++;
		}
		i++;
	}
}

static void	scrolling(double xdelta, double ydelta, void *param)
{
	mlx_t	*window;
	int		old_w;
	int		old_h;

	(void)xdelta;
	window = param;
	old_w = f.sq_w;
	old_h = f.sq_h;
	if (ydelta > 0)
	{
		f.sq_w = (int)(f.sq_w * 1.25);
		f.sq_h = (int)(f.sq_h * 1.25);
	}
	else if (ydelta < 0)
	{
		f.sq_w = (int)(f.sq_w * 0.8);
		f.sq_h = (int)(f.sq_h * 0.8);
	}
	else
		return ;
	if (f.sq_w < 10)
		f.sq_w = 10;
	if (f.sq_h < 10)
		f.sq_h = 10;
	if (f.sq_w > 512)
		f.sq_w = 512;
	if (f.sq_h > 512)
		f.sq_h = 512;
	draw_rectangle(f.image, f.sq_w, f.sq_h, f.color);
	f.image->instances[0].x += ((old_w - f.sq_w) / 2);
	f.image->instances[0].y += ((old_h - f.sq_h) / 2);
}

static void	init_window(mlx_t **window, mlx_image_t **image)
{
	*window = mlx_init(WIDTH, HEIGHT, "Fract-ol", TRUE);
	if (!*window)
		ft_error();
	*image = mlx_new_image(*window, WIDTH, HEIGHT);
	if (!*image || mlx_image_to_window(*window, *image, f.sq_x, f.sq_y) < 0)
	{
		mlx_close_window(*window);
		ft_error();
	}
}

int	main(int argc, char **argv)
{
	mlx_t		*window;

	(void)argv;
	f.sq_w = 128;
	f.sq_h = 128;
	f.sq_x = (WIDTH / 2) - (f.sq_w / 2);
	f.sq_y = (HEIGHT / 2) - (f.sq_h / 2);
	f.color = 0xFF0000FF;
	if (argc > 1)
	{
		init_window(&window, &f.image);
		mlx_loop_hook(window, commands, window);
		mlx_scroll_hook(window, scrolling, window);
		draw_rectangle(f.image, f.sq_w, f.sq_h, f.color);
		mlx_loop(window);
		mlx_terminate(window);
	}
	return (EXIT_SUCCESS);
}
