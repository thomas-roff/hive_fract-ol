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

void	draw_image(void)
{
	int	x;
	int	y;
	int	count;

	y = 1;
	count = 0;
	g_f.scale_x = g_f.target_w / g_f.window_w;
	g_f.scale_y = g_f.target_h / g_f.window_h;
	while (y < g_f.window_h)
	{
		x = 1;
		while (x < g_f.window_w)
		{
			if (g_f.type == 'm')
				draw_mandel(x, y, count);
			else if (g_f.type == 'j')
				draw_julia(x, y, count);
			x++;
		}
		y++;
	}
}
