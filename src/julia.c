/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:42:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:43:23 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	init_julia(t_fract *f)
{
	f->target_x = -2;
	f->target_y = -2;
	f->target_w = 4;
	f->target_h = 4;
	f->color_spread = 10;
	f->color_shift = START_COLOR;
	f->window_w = WIDTH;
	f->window_h = HEIGHT;
	f->julia_angle = ft_atan(f->julia_cx, f->julia_cy);
	f->julia_radius = ft_sqrt(f->julia_cx * f->julia_cx
			+ f->julia_cy * f->julia_cy);
	f->redraw = FALSE;
}

void	rotate_julia(t_fract *f, char c)
{
	if (c == 'l')
		f->julia_angle += (PI / 300);
	if (c == 'r')
		f->julia_angle -= (PI / 300);
	if (f->julia_angle > 2 * PI)
		f->julia_angle -= 2 * PI;
	if (f->julia_angle < 0)
		f->julia_angle += 2 * PI;
	f->julia_cx = f->julia_radius * ft_cos(f->julia_angle);
	f->julia_cy = f->julia_radius * ft_sin(f->julia_angle);
	f->redraw = TRUE;
}

void	julia_pixel(t_fract f, mlx_image_t *image, int pixel_x, int pixel_y)
{
	double	zx;
	double	zy;
	double	temp_zx;
	int		count;

	zx = (double)pixel_x * f.scale_x + f.target_x;
	zy = (double)pixel_y * f.scale_y + f.target_y;
	count = 0;
	while ((zx * zx + zy * zy < 4.0) && (count < MAX_COUNT))
	{
		temp_zx = zx * zx - zy * zy + (double)f.julia_cx;
		zy = 2.0 * zx * zy + (double)f.julia_cy;
		zx = temp_zx;
		count += 1;
	}
	mlx_put_pixel(image, pixel_x, pixel_y, color_pixel(f, count));
}
