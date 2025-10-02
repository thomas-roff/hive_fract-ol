/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:42:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:43:23 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	init_julia(t_fract f, char **argv)
{
	f.julia_cx = ft_atof(argv[2]);
	f.julia_cy = ft_atof(argv[3]);
	f.target_x = -2;
	f.target_y = -2;
	f.target_w = 4;
	f.target_h = 4;
	f.color_spread = 10;
	f.color_shift = START_COLOR;
	f.color_alpha = 0xFF;
	f.window_w = WIDTH;
	f.window_h = HEIGHT;
	f.julia_angle = ft_atan(f.julia_cx, f.julia_cy);
	f.julia_radius = ft_sqrt(f.julia_cx * f.julia_cx
			+ f.julia_cy * f.julia_cy);
}

void	rotate_julia(t_fract f, char c)
{
	if (c == 'l')
		f.julia_angle += 0.01;
	if (c == 'r')
		f.julia_angle -= 0.01;
	f.julia_cx = f.julia_radius * ft_cos(f.julia_angle);
	f.julia_cy = f.julia_radius * ft_sin(f.julia_angle);
	f.redraw = TRUE;
}

void	draw_julia(t_fract f, mlx_image_t *image, int pixel_x, int pixel_y)
{
	double	zx;
	double	zy;
	double	temp_zx;
	int		count;

	zx = (double)pixel_x * (double)f.scale_x + (double)f.target_x;
	zy = (double)pixel_y * (double)f.scale_y + (double)f.target_y;
	count = 0;
	while ((zx * zx + zy * zy < 8.0) && (count < MAX_COUNT))
	{
		temp_zx = zx * zx - zy * zy + (double)f.julia_cx;
		zy = 2.0 * zx * zy + (double)f.julia_cy;
		zx = temp_zx;
		count += 1;
	}
	mlx_put_pixel(image, pixel_x, pixel_y, color_pixel(f, count));
}
