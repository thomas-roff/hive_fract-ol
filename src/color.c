/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:45:01 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:41:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

int	get_color_channel(int color_picker)
{
	color_picker %= COLOR_WHEEL;
	if (color_picker < COLOR_MAX)
		return (color_picker);
	else if (color_picker < 3 * COLOR_MAX)
		return (COLOR_MAX - 1);
	else if (color_picker < 4 * COLOR_MAX)
		return (COLOR_MAX - (color_picker - (COLOR_MAX * 3 - 1)));
	else
		return (0);
}

int	color_pixel(t_fract f, int count)
{
	int			red;
	int			green;
	int			blue;
	int			color_picker;
	uint32_t	color;

	color = 0x000000FF;
	if (count == 0 || count >= MAX_COUNT)
		return (color);
	color_picker = (count * f.color_spread + f.color_shift);
	red = get_color_channel(color_picker);
	green = get_color_channel(color_picker + (COLOR_MAX * 2));
	blue = get_color_channel(color_picker + (COLOR_MAX * 4));
	color = red << 24 | green << 16 | blue << 8 | f.color_alpha;
	return (color);
}

void	color_change(t_fract f, char c)
{
	if (c == 'c')
		f.color_shift += 3;
	if (c == ',')
	{
		f.color_spread -= 1;
		if (f.color_spread < 2)
			f.color_spread = 2;
	}
	if (c == '.')
	{
		f.color_spread += 1;
		if (f.color_spread > 50)
			f.color_spread = 50;
	}
}
