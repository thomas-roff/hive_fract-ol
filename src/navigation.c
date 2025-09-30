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

void	move_image(char axis, float distance)
{
	if (axis == 'x')
		g_f.target_x += distance;
	if (axis == 'y')
		g_f.target_y += distance;
	if (axis == 'z')
	{
		g_f.target_x += distance;
		g_f.target_y += distance;
	}
	draw_image();
}

void	zoom_image(float scale)
{
	g_f.target_w *= scale;
	g_f.target_h *= scale;
}

void	scrolling(double xdelta, double ydelta, void *param)
{
	double	old_centerx;
	double	old_centery;

	(void)xdelta;
	(void)param;
	old_centerx = g_f.target_x + g_f.target_w / 2;
	old_centery = g_f.target_y + g_f.target_h / 2;
	if (ydelta > 0)
		zoom_image(0.9);
	else if (ydelta < 0)
		zoom_image(1.1111111);
	else
		return ;
	if (g_f.target_w > 9)
		g_f.target_w = 9;
	if (g_f.target_h > 9)
		g_f.target_h = 9;
	g_f.target_x = old_centerx - (g_f.target_w / 2);
	g_f.target_y = old_centery - (g_f.target_h / 2);
	draw_image();
}
