/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/12 10:17:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdint.h>

// CODES FOR ERROR TRACKING
// SUCCESSFUL EXECUTION
# define OK 1
// UNSUCCEFUL EXECUTION
# define KO 0

// CODES FOR CHECKING FUNCTIONS
// RETURNS TRUE
# define TRUE 1
// RETURNS FALSE
# define FALSE 0

// WINDOW DIMENSIONS
// WIDTH
# define WIDTH 512
// HEIGHT
# define HEIGHT 512

// FRACT-OL
typedef struct fract_s
{
	mlx_image_t	*image;
	int			sq_x;
	int			sq_y;
	int			sq_w;
	int			sq_h;
	uint32_t	color;
}	fract_t;

#endif
