/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:32:58 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:06:04 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	move_image(t_fract *f, char axis, float distance)
{
	if (axis == 'x')
		f->target_x += distance;
	if (axis == 'y')
		f->target_y += distance;
	if (axis == 'z')
	{
		f->target_x += distance;
		f->target_y += distance;
	}
	f->redraw = TRUE;
}

void	zoom_image(t_fract *f, float scale)
{
	f->target_w *= scale;
	f->target_h *= scale;
}
