/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/09/23 03:19:42 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int key, t_init *game)
{
	if (key == XK_Escape)
		mlx_destroy_window(game->mlx, game->win);
	return (0);
}

//void	ft_error()

void	ft_mem_allocate(t_init *game)
{
//game->mlx = ft_calloc(1, sizeof(void *));
	game->win = ft_calloc(1, sizeof(void *));
	return ;
}

int	main(void)
{
	t_init	game;

	ft_mem_allocate(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	game.win = mlx_new_window(game.mlx, 100, 100, "my first window");
	if (game.win == NULL)
	{
		ft_free_ptr(&game.win);
		return (1);
	}
	mlx_key_hook(game.win, &ft_handle_key, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	ft_free_ptr(game.mlx);
	return (0);
}
