/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:55:58 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/22 16:53:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"
#include <stdio.h>

int get_color_channel(int color_picker)
{
    color_picker %= COLOR_WHEEL;
    if (color_picker < COLOR_MAX - 1)
        return (color_picker);
    else if (color_picker < 3 * COLOR_MAX - 1)
        return (COLOR_MAX - 1);
    else if (color_picker < 4 * COLOR_MAX - 1)
        return (COLOR_MAX - (color_picker - COLOR_WHEEL / 3) - 1);
    else
        return (0);
}

uint32_t    color_pixel(int count)
{
    int         red;
    int         green;
    int         blue;
    int         color_picker;
    uint32_t    color;

    color = 0x000000FF;
    if (count == 0 || count > MAX_COUNT)
        return (color);
    color_picker = (count * f.color_spread + f.color_shift);
    red = get_color_channel(color_picker);
    green = get_color_channel(color_picker + (COLOR_MAX * 2));
    blue = get_color_channel(color_picker + (COLOR_MAX * 4));
    color = red << 24 | green << 16 | blue << 8 | f.color_alpha;
    return (color);
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

void    draw_image()
{
    int x;
    int y;
    int count;

    y = 1;
    count = 0;
    f.scale_x = f.target_w / f.window_w;
    f.scale_y = f.target_h / f.window_h;
    while (y <= f.window_h)
    {
        x = 1;
        while (x <= f.window_w)
        {
            if (f.type == 1)
                draw_mandel(x, y, count);
            // else if (f.type == 2)
            //     draw_julia(x, y);
            x++;
        }
        y++;
    }
}
