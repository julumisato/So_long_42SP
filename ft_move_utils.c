/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:07:16 by jusato            #+#    #+#             */
/*   Updated: 2022/10/10 00:44:31 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_solong *game, int next_x, int next_y)
{
	int	last_x;
	int	last_y;
	int	possible;

	last_x = game->imgs.player_x;
	last_y = game->imgs.player_y;
	possible = ft_check_movement(game, next_x, next_y);
	if (possible)
	{
		if (game->map.mapp[next_x][next_y] == 'C')
			game->map.c_n --;
		game->map.mapp[last_x][last_y] = '0';
		game->map.mapp[next_x][next_y] = 'p';
		game->imgs.player_x = next_x;
		game->imgs.player_y = next_y;
		game->moves ++;
		ft_printf("Move count: %d\n", game->moves);
	}
}

int	ft_check_movement(t_solong *game, int next_x, int next_y)
{
	if (game->map.mapp[next_x][next_y] == '1')
		return (0);
	if (game->map.mapp[next_x][next_y] == 'E'
		&& game->map.c_n == 0)
		ft_close(game, "Game clear!");
	if (game->map.mapp[next_x][next_y] == 'E')
		return (0);
	return (1);
}

void	ft_print_player(t_solong *game)
{
	int	x;
	int	y;

	x = game->imgs.player_x;
	y = game->imgs.player_y;
	mlx_put_image_to_window(game->mlx, game->win,
		game->imgs.player.ptr, y * TILESIZE, x * TILESIZE);
	return ;
}

void	ft_print_move_count(t_solong *game)
{
	char	*count;

	count = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 25, 0xFFFFFF, "Move count:");
	mlx_string_put(game->mlx, game->win, 120, 25, 0xFFFFFF, count);
	free(count);
	return ;
}
