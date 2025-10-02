/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:43:18 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/30 13:35:41 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	init_mandel(void)
{
	g_f.type = 'm';
	g_f.target_x = -2.5;
	g_f.target_y = -2;
	g_f.target_w = 4;
	g_f.target_h = 4;
	g_f.color_spread = 10;
	g_f.color_shift = START_COLOR;
	g_f.color_alpha = 0xFF;
	g_f.window_w = WIDTH;
	g_f.window_h = HEIGHT;
	g_f.max_count = MAX_COUNT;
}

void	draw_mandel(int pixel_x, int pixel_y, int count)
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	temp_zx;

	cx = (double)pixel_x * (double)g_f.scale_x + (double)g_f.target_x;
	cy = (double)pixel_y * (double)g_f.scale_y + (double)g_f.target_y;
	zx = 0.0;
	zy = 0.0;
	count = 0;
	while ((zx * zx + zy * zy < 4.0) && (count < g_f.max_count))
	{
		temp_zx = zx * zx - zy * zy + cx;
		zy = 2.0 * zx * zy + cy;
		zx = temp_zx;
		count += 1;
	}
	mlx_put_pixel(g_f.image, pixel_x, pixel_y, color_pixel(count));
}
