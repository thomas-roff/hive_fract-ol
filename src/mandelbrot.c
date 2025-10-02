/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:43:18 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:41:22 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	init_mandel(t_fract f)
{
	f.target_x = -2.5;
	f.target_y = -2;
	f.target_w = 4;
	f.target_h = 4;
	f.color_spread = 10;
	f.color_shift = START_COLOR;
	f.color_alpha = 0xFF;
	f.window_w = WIDTH;
	f.window_h = HEIGHT;
}

void	draw_mandel(t_fract f, mlx_image_t *image, int pixel_x, int pixel_y)
{
	t_mandel	m;
	int			count;

	m.cx = (double)pixel_x * (double)f.scale_x + (double)f.target_x;
	m.cy = (double)pixel_y * (double)f.scale_y + (double)f.target_y;
	m.zx = 0.0;
	m.zy = 0.0;
	count = 0;
	while ((m.zx * m.zx + m.zy * m.zy < 4.0) && (count < MAX_COUNT))
	{
		m.temp_zx = m.zx * m.zx - m.zy * m.zy + m.cx;
		m.zy = 2.0 * m.zx * m.zy + m.cy;
		m.zx = m.temp_zx;
		count += 1;
	}
	mlx_put_pixel(image, pixel_x, pixel_y, color_pixel(f, count));
}
