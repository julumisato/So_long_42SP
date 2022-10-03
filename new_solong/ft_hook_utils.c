/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:14:32 by jusato            #+#    #+#             */
/*   Updated: 2022/10/04 01:38:14 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_define_hooks(t_solong *game)
{
	mlx_hook(game->win, DestroyNotify, NoEventMask, &ft_close, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_handle_key, game);
	//mlx_loop_hook(game->mlx, ft_refresh, game)
}

int	ft_handle_key(int key, t_solong *game) //have to implement movement too
{
	if (key == XK_Escape || key == XK_q)
		return(ft_close(game));
	else
		return (0);
}

void	ft_free_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return ;
}

int	ft_close(t_solong *game)
{
	//free(game->map.mapp);
	ft_free_map(&game->map, game->map.mapp);
	// if (game->wall.ptr)
	// 	mlx_destroy_image(game->mlx, game->wall.ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);//if display initiated, destroy and free mlx ptr too
	free(game->mlx);
	// ft_free_ptr((void *)&game->mlx);
	exit (0);
}
