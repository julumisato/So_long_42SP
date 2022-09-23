/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/09/23 06:17:50 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int key, t_init *game)
{
	if (key == XK_Escape)
		mlx_destroy_window(game->mlx, game->window->win_p);
	return (0);
}

//void	ft_error()

// void	ft_mem_allocate(t_init *game)
// {
// 	game = ft_calloc(1, sizeof(t_init));
// 	return ;
// }

int	main(void)
{
	t_init	game;

	// ft_mem_allocate(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	
	game.window->height = TILESIZE * 15; //test 
	game.window->width = TILESIZE * 20;	//test
	game.window->win_p = mlx_new_window(game.mlx,
			game.window->width,
			game.window->height,
			"game window");
	if (game.window->win_p == NULL)
	{
		ft_free_ptr(&game.window->win_p);
		return (1);
	}
	mlx_key_hook(game.window->win_p, &ft_handle_key, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.window->win_p);
	game.window->win_p = NULL;
	ft_free_ptr((void *)&game.window->win_p);
	mlx_destroy_display(game.mlx);
	ft_free_ptr((void *)&game.mlx);
	return (0);
}
