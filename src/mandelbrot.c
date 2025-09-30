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

void    init_mandel(void)
{
	f.type = 'm';
	f.target_x = -2.5;
	f.target_y = -2;
	f.target_w = 4;
	f.target_h = 4;
	f.color_spread = 10;
	f.color_shift = START_COLOR;
	f.color_alpha = 0xFF;
	f.window_w = WIDTH;
	f.window_h = HEIGHT;
	f.max_count = MAX_COUNT;
}

void    draw_mandel(int pixel_x, int pixel_y, int count)
{
    double   zx;
    double   zy;
    double   cx;
    double   cy;
    double   temp_zx;

    cx = pixel_x * f.scale_x + f.target_x;
    cy = pixel_y * f.scale_y + f.target_y;
    zx = 0;
    zy = 0;
    count = 0;
    while ((zx * zx + zy * zy < 4.0) && (count < f.max_count))
    {
        temp_zx = zx * zx - zy * zy + cx;
        zy = 2.0 * zx * zy + cy;
        zx = temp_zx;
        count += 1;
    }
    mlx_put_pixel(f.image, pixel_x, pixel_y, color_pixel(count));
}
