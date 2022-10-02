/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/10/02 05:51:40 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return ;
}

void	ft_free_map(t_map *map, char **map_mat)
{
	int	i;

	i = 0;
	while(i <= map->rows)
		free(map_mat[i ++]);
	free(map_mat);
	return ;
}

void	ft_exit(t_solong *game, char *message, int flag)
{
	ft_printf("Aborting game.\nMessage: '%s'\n", message);
	if (flag < 0)
	{
		if (game->map.map)
			ft_free_map(&game->map, game->map.map);
		if (game->map.path)
			ft_free_ptr((void *)game->map.path);
	}
	exit (0) ;
}

void	ft_mlx_init(t_solong *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit (0);
	return ;
}

void	ft_init_variables(t_solong *game)
{
	game->win_x = 0;
	game->win_y = 0;
}

int	ft_close(t_solong *game)
{
	mlx_destroy_window(game->mlx, game->win_p);
	game->win_p = NULL;
	//destroy images when implemented
	//free allocated memory
	ft_free_map(&game->map, game->map.map);
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

void	ft_init_game(t_solong *game, int argc, char **argv)
{
	ft_init_map(game, argc, argv);
	ft_mlx_init(game);
	game->win_y = TILESIZE * 12;
	game->win_x = TILESIZE * 20;
	game->win_p = mlx_new_window(game->mlx, game->win_x, game->win_y, "so_long");
	if (game->win_p == NULL)
		ft_close(game);
	return ;
}

int	main(int argc, char **argv)
{
	t_solong	game;

	ft_init_variables(&game);
	ft_init_game(&game, argc, argv);
	mlx_hook(game.win_p, DestroyNotify, NoEventMask, ft_close, &game);
	mlx_hook(game.win_p, KeyPress, KeyPressMask, ft_handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
