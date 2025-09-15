/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:31:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/12 10:24:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_tester(void *param)
{
	mlx_t	*window;

	window = param;
	if (mlx_is_key_down(window, MLX_KEY_ESCAPE))
		mlx_close_window(window);
}

int	main(int argc, char **argv)
{
	mlx_t	*window;
	mlx_image_t *image;

	(void)argv;
	if (argc > 1)
	{
		window = mlx_init(WIDTH, HEIGHT, "Fract-ol", TRUE);
		if (!window)
		{
			perror("Window failed to open");
			return (EXIT_FAILURE);
		}
		image = mlx_new_image(window, 128, 128);
		if (!image)
		{
			mlx_close_window(window);
			perror("Image failed to initiate");
			return (EXIT_FAILURE);
		}
		if (mlx_image_to_window(window, image, 0, 0) == -1)
		{
			mlx_close_window(window);
			perror("Image failed to connect to winddow");
			return (EXIT_FAILURE);
		}
		mlx_loop_hook(window, ft_tester, window);
		mlx_loop(window);
		mlx_terminate(window);
	}
	return (EXIT_SUCCESS);
}
