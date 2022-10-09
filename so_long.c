/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:46:16 by jusato            #+#    #+#             */
/*   Updated: 2022/10/09 22:33:51 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_variables(t_solong *game)
{
	game->win_x = 0;
	game->win_y = 0;
	game->init = 0;
	game->map.rows = 0;
	game->map.cols = 0;
	game->map.init = 0;
	game->imgs.init = 0;
	game->map.c_n = 0;
	game->map.e_n = 0;
	game->map.p_n = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_solong	game;

	ft_init_variables(&game);
	if (ft_init_game(&game, argc, argv) != 0)
		return (ft_close(&game, "error while initializing the game"));
	ft_define_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
