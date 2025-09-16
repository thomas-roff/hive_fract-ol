/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:18:00 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/16 14:18:51 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"
#include <stdlib.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Function to draw a rectangle on the image
void draw_rectangle(mlx_image_t* image, int x, int y, int width, int height, uint32_t color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mlx_put_pixel(image, x + j, y + i, color);
        }
    }
}

int main(void) {
    // Initialize MLX42
    if (!mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MLX42 - Draw Rectangle", true)) {
        fprintf(stderr, "MLX42 initialization failed\n");
        return EXIT_FAILURE;
    }

    mlx_t* mlx = mlx_get_instance();

    // Create an image to draw on
    mlx_image_t* image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!image) {
        fprintf(stderr, "Failed to create image\n");
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

    // Attach the image to the window
    mlx_image_to_window(mlx, image, 0, 0);

    // Draw a rectangle at (100, 100) with size 200x150 and color red
    uint32_t red = 0xFF0000FF; // RGBA (Red, Green, Blue, Alpha)
    draw_rectangle(image, 100, 100, 200, 150, red);

    // Run the event loop
    mlx_loop(mlx);

    // Clean up resources
    mlx_delete_image(mlx, image);
    mlx_terminate(mlx);

    return EXIT_SUCCESS;
}
