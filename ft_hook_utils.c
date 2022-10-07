/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:14:32 by jusato            #+#    #+#             */
/*   Updated: 2022/10/07 05:58:49 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_define_hooks(t_solong *game)
{
	mlx_hook(game->win, DestroyNotify, NoEventMask, &ft_close, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_handle_key, game);
	mlx_loop_hook(game->mlx, &ft_update_game, game);
	return ;
}

int	ft_handle_key(int key, t_solong *game)
{
	if (key == XK_Escape || key == XK_q)
		return (ft_close(game, "exit game"));
/*	
	if (key == XK_a || key == XK_Left)
		ft_moveleft(game);
	if (key == XK_s || key == XK_Down)
		ft_movedown(game);
	if (key == XK_d || key == XK_Right)
		ft_moveright(game);
	if (key == XK_w || key == XK_Up)
		ft_moveup(game);
*/
	return (0);
}

int	ft_update_game(t_solong *game)
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
	// ft_print_player(game);
	// ft_print_move_count(game);
	return (0);
}
