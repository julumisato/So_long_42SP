/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:14:32 by jusato            #+#    #+#             */
/*   Updated: 2022/10/18 05:50:14 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_define_hooks(t_solong *game)
{
	mlx_hook(game->win, DestroyNotify, NoEventMask, &ft_end_when_press_x, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_handle_key, game);
	mlx_loop_hook(game->mlx, &ft_update_loop, game);
	return ;
}

int	ft_handle_key(int key, t_solong *game)
{
	int	row;
	int	col;

	col = game->imgs.player_x;
	row = game->imgs.player_y;
	if (key == XK_Escape || key == XK_q)
		ft_close(game, "exit game");
	if (key == XK_w || key == XK_Up)
		row --;
	if (key == XK_s || key == XK_Down)
		row ++;
	if (key == XK_d || key == XK_Right)
		col ++;
	if (key == XK_a || key == XK_Left)
		col --;
	if (row != game->imgs.player_y || col != game->imgs.player_x)
		ft_move_player(game, row, col);
	return (1);
}

int	ft_update_loop(t_solong *game)
{
	int	row;
	int	col;

	ft_print_map(game);
	row = 0;
	while (game->map.mapp[row])
	{
		col = 0;
		while (game->map.mapp[row][col])
		{
			if (game->map.mapp[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.collect.ptr, col * TILESIZE, row * TILESIZE);
			if (game->map.mapp[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.goal.ptr, col * TILESIZE, row * TILESIZE);
			col ++;
		}
		row ++;
	}
	ft_print_player(game);
	ft_print_move_count(game);
	return (0);
}
