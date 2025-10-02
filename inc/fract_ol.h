/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:44:16 by thblack-         ###   ########.fr       */
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
# define MAX_COUNT 100
// DESCRETE COLORS ON COLOR WHEEL
# define COLOR_WHEEL 1536
// SIZE OF SIDE ON COLOR WHEEL & MAX VALUE OF COLOR IN HEX
# define COLOR_MAX 256
// START COLOUR (GREEN = 0, RED = 512, BLUE = 1024)
# define START_COLOR 1024

// FRACT-OL
typedef struct s_fract
{
	char		type;
	double		target_x;
	double		target_y;
	double		target_w;
	double		target_h;
	double		scale_x;
	double		scale_y;
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
	int			redraw;
}	t_fract;

typedef struct s_mandel
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	temp_zx;
}	t_mandel;

typedef struct s_julia
{
	double	zx;
	double	zy;
	double	temp_zx;
}	t_julia;

// MAIN FUNCTIONS
int		main(int argc, char **argv);
void	commands(void *param);
void	scrolling(double xdelta, double ydelta, void *param);
void	draw_image(t_fract f, mlx_image_t *image);

// INITIALIZATION
int		parse_input(char type, char **argv);
void	init_window(mlx_t **window, mlx_image_t **image);

// NAVIGATION
void	move_image(t_fract f, char axis, float distance);
void	zoom_image(t_fract f, float scale);

// COLOR
int		get_color_channel(int color_picker);
void	color_change(t_fract f, char c);
int		color_pixel(t_fract f, int count);

// MANDELBROT
void	init_mandel(t_fract f);
void	draw_mandel(t_fract f, mlx_image_t *image, int pixel_x, int pixel_y);

// JULIA
void	rotate_julia(t_fract f, char c);
void	init_julia(t_fract f, char **argv);
void	draw_julia(t_fract f, mlx_image_t *image, int pixel_x, int pixel_y);

// FT_ATOF
int		ft_power(int base, int exponent);
int		ft_naf(const char *nptr);
float	ft_atof(const char *nptr);

// MATHEMATIC FUNCTIONS
double	ft_sin(double x);
double	ft_cos(double x);
double	ft_sqrt(double nbr);
double	ft_atan(double x, double y);

// MESSAGES
void	ft_error(void);
void	input_helper(void);
void	input_prompt(void);

#endif
