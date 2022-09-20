/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/09/20 05:37:03 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int key, t_init *game)
{
	if (key == XK_Escape)
		mlx_destroy_window(game->mlx, game->win);
	return (0);
}

int	main(void)
{
	t_init	*game;

	game = NULL;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->win = mlx_new_window(game->mlx, 100, 100, "my first window");
	if (game->win == NULL)
	{
		ft_free_ptr(&game->win);
		return (1);
	}
	mlx_key_hook(game->win, &ft_handle_key, &game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_ptr(&game->mlx);
	free(game);
	return (0);
}
