/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/22 17:15:25 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdint.h>

// SUCCESSFUL EXECUTION
# define OK 1
// UNSUCCEFUL EXECUTION
# define KO 0
// RETURNS TRUE
# define TRUE 1
// RETURNS FALSE
# define FALSE 0
// WINDOW WIDTH
# define WIDTH 512
// WINDOW HEIGHT
# define HEIGHT 512
// MAXIMUM ITERATIONS OF FRACTAL OPERATION
# define MAX_COUNT 60
// DESCRETE COLORS ON COLOR WHEEL
# define COLOR_WHEEL 1535
// SIZE OF SIDE ON COLOR WHEEL & MAX VALUE OF COLOR IN HEX
# define COLOR_MAX 256

// FRACT-OL
typedef struct s_fract
{
	mlx_image_t	*image;
	float		target_x;
	float		target_y;
	float		target_w;
	float		target_h;
	float		scale_x;
	float		scale_y;
	int			window_h;
	int			window_w;
	int			color_shift;
	int			color_spread;
	int			color_alpha;
	uint32_t	color;
	int			max_count;
	int			type;
}	t_fract;

extern t_fract	f;

// FRACT-OL FUNCTIONS

// DRAW FUNCTIONS
void    draw_image();

#endif
