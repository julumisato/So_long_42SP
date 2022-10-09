/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 06:48:53 by jusato            #+#    #+#             */
/*   Updated: 2022/10/10 00:45:17 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_solong *game, char *message)
{
	ft_printf("Closing game...\nMessage: %s\n", message);
	if (game->map.init == 1)
		ft_free_map(&game->map, game->map.mapp);
	if (game->imgs.init == 1)
	{
		mlx_destroy_image(game->mlx, game->imgs.wall.ptr);
		mlx_destroy_image(game->mlx, game->imgs.grass.ptr);
		mlx_destroy_image(game->mlx, game->imgs.player.ptr);
		mlx_destroy_image(game->mlx, game->imgs.collect.ptr);
		mlx_destroy_image(game->mlx, game->imgs.goal.ptr);
	}
	if (game->init == 1)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (0);
}

int	ft_end_when_pressing_x(t_solong *game)
{
	ft_close(game, "Close game");
	return (0);
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
