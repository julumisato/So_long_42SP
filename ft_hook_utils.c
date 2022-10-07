/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:14:32 by jusato            #+#    #+#             */
/*   Updated: 2022/10/07 05:08:46 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_define_hooks(t_solong *game)
{
	mlx_hook(game->win, DestroyNotify, NoEventMask, &ft_close, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_handle_key, game);
}

int	ft_handle_key(int key, t_solong *game)
{
	if (key == XK_Escape || key == XK_q)
		return (ft_close(game, "exit game"));
	else
		return (0);
}
