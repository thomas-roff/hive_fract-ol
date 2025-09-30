/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:55:58 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/30 13:11:25 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"
#include <stdio.h>

void    draw_image()
{
    int x;
    int y;
    int count;

    y = 1;
    count = 0;
    f.scale_x = f.target_w / f.window_w;
    f.scale_y = f.target_h / f.window_h;
    while (y < f.window_h)
    {
        x = 1;
        while (x < f.window_w)
        {
            if (f.type == 'm')
                draw_mandel(x, y, count);
            else if (f.type == 'j')
                draw_julia(x, y, count);
            x++;
        }
        y++;
    }
}
