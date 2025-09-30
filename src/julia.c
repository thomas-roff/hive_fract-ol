/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:42:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/30 13:13:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"
#include <stdio.h>

void	init_julia(char **argv)
{
	(void)argv;
	g_f.type = 'j';
	// g_f.julia_cx = ft_atof(argv[2]);
	// g_f.julia_cy = ft_atof(argv[3]);
	// printf("CX: %f\n", g_f.julia_cx);
	// printf("CY: %f\n", g_f.julia_cy);
	g_f.target_x = -2;
	g_f.target_y = -2;
	g_f.target_w = 4;
	g_f.target_h = 4;
	g_f.color_spread = 10;
	g_f.color_shift = START_COLOR;
	g_f.color_alpha = 0xFF;
	g_f.window_w = WIDTH;
	g_f.window_h = HEIGHT;
	g_f.max_count = MAX_COUNT;
	g_f.julia_angle = ft_atan(g_f.julia_cx, g_f.julia_cy);
	g_f.julia_radius = ft_sqrt(g_f.julia_cx * g_f.julia_cx
			+ g_f.julia_cy * g_f.julia_cy);
}

void	rotate_julia(char c)
{
	if (c == 'l')
		g_f.julia_angle += 0.01;
	if (c == 'r')
		g_f.julia_angle -= 0.01;
	g_f.julia_cx = g_f.julia_radius * ft_cos(g_f.julia_angle);
	g_f.julia_cy = g_f.julia_radius * ft_sin(g_f.julia_angle);
	draw_image();
}

void	draw_julia(int pixel_x, int pixel_y, int count)
{
	double	zx;
	double	zy;
	double	temp_zx;

	zx = pixel_x * g_f.scale_x + g_f.target_x;
	zy = pixel_y * g_f.scale_y + g_f.target_y;
	count = 0;
	while ((zx * zx + zy * zy < 8.0) && (count < g_f.max_count))
	{
		temp_zx = zx * zx - zy * zy + g_f.julia_cx;
		zy = 2.0 * zx * zy + g_f.julia_cy;
		zx = temp_zx;
		count += 1;
	}
	mlx_put_pixel(g_f.image, pixel_x, pixel_y, color_pixel(count));
}
