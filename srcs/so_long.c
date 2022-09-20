/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/09/20 04:15:01 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	win = mlx_new_window(mlx, 500, 500, "my first window");
	if (win == NULL)
	{
		free(win);
		return (1);
	}
	while (1)
		;
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	ft_free_ptr(mlx);
}
