/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:07:16 by jusato            #+#    #+#             */
/*   Updated: 2022/10/14 06:14:08 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_solong *game, int next_row, int next_col)
{
	int	last_row;
	int	last_col;
	int	possible;

	last_row = game->imgs.player_y;
	last_col = game->imgs.player_x;
	possible = ft_check_movement(game, next_row, next_col);
	if (possible)
	{
		if (game->map.mapp[next_row][next_col] == 'C')
			game->map.c_n --;
		game->map.mapp[last_row][last_col] = '0';
		game->map.mapp[next_row][next_col] = 'p';
		game->imgs.player_y = next_row;
		game->imgs.player_x = next_col;
		game->moves ++;
		ft_printf("Move count: %d\n", game->moves);
	}
}

int	ft_check_movement(t_solong *game, int next_row, int next_col)
{
	if (game->map.mapp[next_row][next_col] == '1')
		return (0);
	if (game->map.mapp[next_row][next_col] == 'E'
		&& game->map.c_n == 0)
		ft_close(game, "Game clear!");
	if (game->map.mapp[next_row][next_col] == 'E')
		return (0);
	return (1);
}

void	ft_print_player(t_solong *game)
{
	int	row;
	int	col;

	row = game->imgs.player_y;
	col = game->imgs.player_x;
	mlx_put_image_to_window(game->mlx, game->win,
		game->imgs.player.ptr, col * TILESIZE, row * TILESIZE);
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
