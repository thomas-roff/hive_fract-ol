/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/30 13:15:07 by thblack-         ###   ########.fr       */
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
# define COLOR_WHEEL 1536
// SIZE OF SIDE ON COLOR WHEEL & MAX VALUE OF COLOR IN HEX
# define COLOR_MAX 256
// START COLOUR (GREEN = 0, RED = 512, BLUE = 1024)
# define START_COLOR 1024

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
	float		julia_cx;
	float		julia_cy;
	double		julia_angle;
	double		julia_radius;
	int			window_h;
	int			window_w;
	int			color_shift;
	int			color_spread;
	int			color_alpha;
	uint32_t	color;
	int			max_count;
	char		type;
}	t_fract;

extern t_fract	f;

// FRACT-OL FUNCTIONS

// DRAW FUNCTIONS
void		draw_image();

// NAVIGATION
void	move_image(char axis, float distance);
void	scrolling(double xdelta, double ydelta, void *param);

// COLOR
int			get_color_channel(int color_picker);
uint32_t    color_pixel(int count);
void		color_change(char c);

// MANDELBROT
void    init_mandel(void);
void    draw_mandel(int pixel_x, int pixel_y, int count);

// JULIA
double  ft_sin(double x);
double  ft_cos(double x);
void    rotate_julia(char c);
void    init_julia();
void    draw_julia(int pixel_x, int pixel_y, int count);

// FT_ATOF
int		ft_power(int base, int exponent);
float	ft_atof(const char *nptr);

// MATHEMATIC FUNCTIONS
double  ft_sin(double x);
double  ft_cos(double x);
double  ft_sqrt(double nbr);
double	ft_atan(double x, double y);

#endif
