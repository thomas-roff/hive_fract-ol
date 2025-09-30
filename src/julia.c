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

void    init_julia()
{
    f.type = 'j';
	f.target_x = -2;
	f.target_y = -2;
	f.target_w = 4;
	f.target_h = 4;
	f.color_spread = 10;
	f.color_shift = START_COLOR;
	f.color_alpha = 0xFF;
	f.window_w = WIDTH;
	f.window_h = HEIGHT;
	f.max_count = MAX_COUNT;
	f.julia_angle = ft_atan(f.julia_cx, f.julia_cy);
    f.julia_radius = ft_sqrt(f.julia_cx * f.julia_cx
                             + f.julia_cy * f.julia_cy);
}

void    rotate_julia(char c)
{
    if (c == 'l')
        f.julia_angle += 0.01;
    if (c == 'r')
        f.julia_angle -= 0.01;
    f.julia_cx = f.julia_radius * ft_cos(f.julia_angle);
    f.julia_cy = f.julia_radius * ft_sin(f.julia_angle);
	draw_image();
}

void    draw_julia(int pixel_x, int pixel_y, int count)
{
    double   zx;
    double   zy;
    double   temp_zx;

    zx = pixel_x * f.scale_x + f.target_x;
    zy = pixel_y * f.scale_y + f.target_y;
    count = 0;
    while ((zx * zx + zy * zy < 8.0) && (count < f.max_count))
    {
        temp_zx = zx * zx - zy * zy + f.julia_cx;
        zy = 2.0 * zx * zy + f.julia_cy;
        zx = temp_zx;
        count += 1;
    }
    mlx_put_pixel(f.image, pixel_x, pixel_y, color_pixel(count));
}
