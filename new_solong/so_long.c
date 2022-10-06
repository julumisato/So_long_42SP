/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:46:16 by jusato            #+#    #+#             */
/*   Updated: 2022/10/06 06:23:19 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_solong *game, char *message)
{
	ft_printf("Aborting game.\nMessage: '%s'\n", message);
	if (game->map.mapp && game->map.rows > 0)
		ft_free_map(&game->map, game->map.mapp);
	exit (0);
}

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

void	ft_print_map(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.mapp[i])
	{
		j = 0;
		while (game->map.mapp[i][j])
		{
			if (game->map.mapp[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall.ptr, j * TILESIZE, i * TILESIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->imgs.grass.ptr, j * TILESIZE, i * TILESIZE);
			j ++;
		}
		i ++;
	}
	return ;
}

int	ft_get_images(t_solong *game)
{
	game->imgs.wall.ptr = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &game->imgs.wall.x, &game->imgs.wall.y);
	game->imgs.grass.ptr = mlx_xpm_file_to_image(game->mlx, GRASS_PATH, &game->imgs.grass.x, &game->imgs.grass.y);
	// game->imgs.player.ptr = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &game->imgs.player.x, &game->imgs.player.y);
	// game->imgs.collect.ptr = mlx_xpm_file_to_image(game->mlx, COLLECT_PATH, &game->imgs.collect.x, &game->imgs.collect.y);
	// game->imgs.goal.ptr = mlx_xpm_file_to_image(game->mlx, GOAL_PATH, &game->imgs.goal.x, &game->imgs.goal.y);
	if (!game->imgs.wall.ptr || !game->imgs.grass.ptr) //|| !game->imgs.player.ptr || !game->imgs.collect.ptr || !game->imgs.goal.ptr)
		ft_exit(game, "Error while loading images\n");
	game->imgs.init = 1;
	return (0);
}

int	ft_init_game(t_solong *game, int argc, char **argv)
{
	ft_init_map(game, argc, argv);	//Reading map
	if (ft_mlx_and_window_init(game) != 0)	//init mlx & init window;
		return (-1);
	ft_get_images(game);	/*init images -> implement functions to initiate all images*/
	ft_print_map(game);		/*print map -> implement function to print the whole map on the window*/
	//mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall.ptr, 0 * TILESIZE, 0 * TILESIZE);
	//mlx_put_image_to_window(game->mlx, game->win, game->imgs.grass.ptr, 1 * TILESIZE, 1 * TILESIZE);
	return (0);
}

void	ft_init_variables(t_solong *game)
{
	game->win_x = 0;
	game->win_y = 0;
	game->map.rows = 0;
	game->map.cols = 0;
	game->map.init = 0;
	game->imgs.init = 0;
}

int	main(int argc, char **argv)
{
	t_solong	game;

	ft_init_variables(&game);
	if (ft_init_game(&game, argc, argv) != 0)
		return (ft_printf("error while initializing the game"));
	ft_define_hooks(&game);
	mlx_loop(game.mlx);
	// ft_free_map(&game.map, game.map.mapp);
	// mlx_destroy_window(game.mlx, game.win);
	// mlx_destroy_display(game.mlx);//if display initiated, destroy and free mlx ptr too
	// free(game.mlx);
	return (0);
}
