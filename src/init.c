/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:04:09 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/02 16:04:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

int	parse_input(t_fract *f, int argc, char **argv)
{
	int	flag;

	flag = KO;
	if (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "Mandelbrot")
		|| !ft_strcmp(argv[1], "m") || !ft_strcmp(argv[1], "M"))
	{
		flag = OK;
		f->type = 'm';
		if (argc != 2)
			return (KO);
	}
	else if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "Julia")
		|| !ft_strcmp(argv[1], "j") || !ft_strcmp(argv[1], "J"))
	{
		flag = OK;
		f->type = 'j';
		if (argc != 4 || !ft_naf(argv[2]) || !ft_naf(argv[3]))
			return (KO);
	}
	else if (!ft_strcmp(argv[1], "-help"))
		input_helper();
	return (flag);
}

void	init_window(mlx_t **window, mlx_image_t **image)
{
	*window = mlx_init(WIDTH, HEIGHT, "Fract-ol", FALSE);
	if (!window || !*window)
		ft_error();
	*image = mlx_new_image(*window, WIDTH, HEIGHT);
	if (!*image || mlx_image_to_window(*window, *image, 0, 0) < 0)
	{
		mlx_close_window(*window);
		ft_error();
	}
}
