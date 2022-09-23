/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/09/24 01:57:47 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int key, t_solong *game)
{
	if (key == XK_Escape)
		mlx_destroy_window(game->mlx, game->window->win_p);
	return (0);
}

void	ft_validate(int argc, char *map_path)
{
	// int	fd;

	if (argc != 2)
		exit (1);
	if (ft_strncmp(&map_path[ft_strlen(map_path) - 4], ".ber", 4) != 0)
	{
		printf("invalid map format!\n");
		exit (1);
	}
	return ;
}

void	ft_allocate_game_memory(t_solong *game)
{
	game->window = ft_calloc(1, sizeof(t_win));
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->window)
		exit (1);
	//ft_free_ptr(&game->map->map_ptr); //TEST
	return ;
}

int	main(int argc, char **argv)
{
	t_solong	game;

	ft_validate(argc, argv[1]);
	ft_allocate_game_memory(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	game.window->y = TILESIZE * 15;
	game.window->x = TILESIZE * 20;
	game.window->win_p = mlx_new_window(game.mlx,
			game.window->x,
			game.window->y,
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
