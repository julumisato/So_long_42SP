/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:07:16 by jusato            #+#    #+#             */
/*   Updated: 2022/10/09 23:33:44 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		//ft_printf("Move count: %d\n", game->moves);
	}
}
