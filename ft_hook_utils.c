/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:14:32 by jusato            #+#    #+#             */
/*   Updated: 2022/10/09 19:30:07 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_define_hooks(t_solong *game)
{
	mlx_hook(game->win, DestroyNotify, NoEventMask, &ft_close, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_handle_key, game);
	mlx_loop_hook(game->mlx, &ft_update_loop, game);
	return ;
}

int	ft_handle_key(int key, t_solong *game)
{
	int	row;
	int	col;

	row = game->imgs.player_x;
	col = game->imgs.player_y;
	if (key == ESC || key == QUIT)
		ft_close(game, "exit game");
	if (key == XK_w || key == XK_Up)
		row --;
	if (key == XK_s || key == XK_Down)
		row ++;
	if (key == XK_d || key == XK_Right)
		col ++;
	if (key == XK_a || key == XK_Left)
		col --;
	ft_move_player(game, row, col);

	return (1);
}

int	ft_update_loop(t_solong *game)
{
	int	i;
	int	j;

	ft_print_map(game);
	i = 0;
	while (game->map.mapp[i])
	{
		j = 0;
		while (game->map.mapp[i][j])
		{
			if (game->map.mapp[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.player.ptr, j * TILESIZE, i * TILESIZE);
			if (game->map.mapp[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.collect.ptr, j * TILESIZE, i * TILESIZE);
			if (game->map.mapp[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.goal.ptr, j * TILESIZE, i * TILESIZE);
			j ++;
		}
		i ++;
	}
	// ft_print_move_count(game);
	return (0);
}
