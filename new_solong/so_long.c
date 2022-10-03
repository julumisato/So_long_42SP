/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:46:16 by jusato            #+#    #+#             */
/*   Updated: 2022/10/03 21:53:58 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_init_game(t_solong *game, argc, **argv)
// {
// 	//readmap
// 	//
// }

int	main()
{
	t_solong	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 100, 100, "init window");
	game.wall.ptr = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &game.wall.x, &game.wall.y);
	game.grass.ptr = mlx_xpm_file_to_image(game.mlx, "assets/grass.xpm", &game.grass.x, &game.grass.y);
	if (!game.wall.ptr || !game.grass.ptr)
		return(ft_printf("no image!!\n"));
	mlx_put_image_to_window(game.mlx, game.win, game.wall.ptr, 0 * TILESIZE, 0 * TILESIZE);
	mlx_put_image_to_window(game.mlx, game.win, game.grass.ptr, 1 * TILESIZE, 1 * TILESIZE);
	mlx_loop(game.mlx);
	return (0);
}
