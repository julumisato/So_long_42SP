/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/09/08 03:59:42 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#define WIDTH 600
#define HEIGHT 300

#define MLX_ERROR 1

int	main(void)
{
	void	*mlx_ptr;
	void	*window_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	window_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "my first window");
	if (window_ptr == NULL)
	{
		free(window_ptr);
		return (MLX_ERROR);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, window_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
