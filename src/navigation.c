/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:32:58 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/30 13:44:57 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void    move_image(char axis, float distance)
{
    if (axis == 'x')
		f.target_x += distance;
    if (axis == 'y')
		f.target_y += distance;
    if (axis == 'z')
    {
		f.target_x += distance;
		f.target_y += distance;
    }
    draw_image();
}

void    zoom_image(float scale)
{
    f.target_w *= scale;
    f.target_h *= scale;
}

void	scrolling(double xdelta, double ydelta, void *param)
{
	double	old_centerx;
	double	old_centery;

	(void)xdelta;
	(void)param;
	old_centerx = f.target_x + f.target_w / 2;
    old_centery = f.target_y + f.target_h / 2;
	if (ydelta > 0)
        zoom_image(0.9);
	else if (ydelta < 0)
        zoom_image(1.1111111);
	else
		return ;
	if (f.target_w > 9)
		f.target_w = 9;
	if (f.target_h > 9)
		f.target_h = 9;
	f.target_x = old_centerx - (f.target_w / 2);
	f.target_y = old_centery - (f.target_h / 2);
	draw_image();
}

