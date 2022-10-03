/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:46:16 by jusato            #+#    #+#             */
/*   Updated: 2022/10/04 01:48:42 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_and_window_init(t_solong *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_exit(game, "failed to initiate mlx.");
	game->win_y = TILESIZE * game->map.rows;
	game->win_x = TILESIZE * game->map.cols;
	game->win = mlx_new_window(game->mlx, game->win_x, game->win_y, "so_long game window");
	if (game->win == NULL)
		ft_exit(game, "failed to initiate window.");
	return (0);
}

int	ft_init_game(t_solong *game, int argc, char **argv)
{
	//Reading map
	ft_init_map(game, argc, argv);
	//init mlx & init window;
	if (ft_mlx_and_window_init(game) != 0)
		return (-1);
	//init images
	//game->wall.ptr = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &game->wall.x, &game->wall.y);
	//game->grass.ptr = mlx_xpm_file_to_image(game->mlx, GRASS_PATH, &game->grass.x, &game->grass.y);
	// if (!game->wall.ptr || !game->grass.ptr)
	// 	return(ft_printf("no image!!\n"));
	//print images
	//mlx_put_image_to_window(game->mlx, game->win, game->wall.ptr, 0 * TILESIZE, 0 * TILESIZE);
	// mlx_put_image_to_window(game->mlx, game->win, game->grass.ptr, 1 * TILESIZE, 1 * TILESIZE);
	return (0);
}

void	ft_init_variables(t_solong *game)
{
	game->win_x = 0;
	game->win_y = 0;
	game->map.rows = 0;
	game->map.cols = 0;
	//game->map.mapp = NULL;
}

int	main(int argc, char **argv)
{
	t_solong	game;

	ft_init_variables(&game);
	if (ft_init_game(&game, argc, argv) != 0)
		return (ft_printf("error while initializing the game"));
	//ft_define_hooks(&game);
	//mlx_loop(game.mlx);
	ft_free_map(&game.map, game.map.mapp);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);//if display initiated, destroy and free mlx ptr too
	free(game.mlx);
	return (0);
}
