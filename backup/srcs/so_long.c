/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/10/04 01:08:14 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return ;
}

void	ft_free_map(t_map *map, char **map_mat)
{
	int	i;

	i = 0;
	while (i <= map->rows)
	{
		free(map_mat[i]);
		i ++;
	}
	free(map_mat);
	return ;
}

void	ft_exit(t_solong *game, char *message)
{
	ft_printf("Aborting game.\nMessage: '%s'\n", message);
	if (game->map.map && game->map.rows > 0)
		ft_free_map(&game->map, game->map.map);
	
	//free(game.mlx)
	exit (0);
}

void	ft_init_variables(t_solong *game)
{
	game->win_x = 0;
	game->win_y = 0;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.map = NULL;
	// game->imgs.wall.sizex = 0;
	// game->imgs.wall.sizey = 0;
}

int	ft_close(t_solong *game)
{
	ft_free_map(&game->map, game->map.map);
	mlx_destroy_window(game->mlx, game->win_p);
	game->win_p = NULL;
	//destroy images when implemented
	//free allocated memory
//	ft_free_map(&game->map, game->map.map);
	//ft_free_map(&game->map, game->map.map);
	mlx_destroy_display(game->mlx);//if display initiated, destroy and free mlx ptr too
	ft_free_ptr((void *)&game->mlx);
	exit (0);
}

int	ft_handle_key(int key, t_solong *game)
{
	if (key == XK_Escape || key == XK_q)
		ft_close(game);
	return (0);
}

int	ft_mlx_and_window_init(t_solong *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_exit(game, "failed to initiate mlx.");
	game->win_y = TILESIZE * game->map.rows;
	game->win_x = TILESIZE * game->map.columns;
	game->win_p = mlx_new_window(game->mlx, game->win_x, game->win_y, "so_long game window");
	if (game->win_p == NULL)
		ft_exit(game, "failed to initiate window.");
	return (0);
}

int	ft_init_game(t_solong *game, int argc, char **argv)
{
	ft_init_map(game, argc, argv);
	if (ft_mlx_and_window_init(game) != 0)
		return (-1);
	//implement functions to print images to the screen
	//ft_init_images(game);
	//ft_print_images(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	game;

	ft_init_variables(&game);
	if (ft_init_game(&game, argc, argv) != 0)
		return (0);
	mlx_hook(game.win_p, DestroyNotify, NoEventMask, ft_close, &game);
	mlx_hook(game.win_p, KeyPress, KeyPressMask, ft_handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}