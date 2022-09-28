/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:52 by jusato            #+#    #+#             */
/*   Updated: 2022/09/28 04:27:31 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_init(t_solong *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit (0);
	return ;
}

void	ft_validate(t_solong *game, int argc, char *map_path)
{
	// char	*mapstr;
	// int		fd;
	// int		line;

	if (argc != 2)
		exit (1);
	if (ft_strncmp(&map_path[ft_strlen(map_path) - 4], ".ber", 4) != 0)
	{
		ft_printf("invalid map format!\n");
		exit (1);
	}
	// fd = open(map_path, O_RDONLY);
	// line = 0;
	// while(1)
	// {
	// 	mapstr = get_next_line(fd);
	// 	if (mapstr == NULL)
	// 		break ;
	// 	ft_printf("%s", mapstr);
	// 	free(mapstr);
	// 	line ++;
	// }
	// close(fd);
	// ft_printf("\nline lenght: %d\n", line);
	(void)game;
	return ;
}

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return ;
}

int	ft_close(t_solong *game)
{
	mlx_destroy_window(game->mlx, game->win_p);
	game->win_p = NULL;
	//destroy images when implemented
	//free allocated memory
	mlx_destroy_display(game->mlx);//if display initiated, destroy and free mlx ptr too
	ft_free_ptr((void *)&game->mlx);
	exit (0);
}

int	ft_handle_key(int key, t_solong *game)
{
	if (key == XK_Escape || key == XK_q)
		ft_close(game);
	return (0);
}

void	ft_specify_hooks(t_solong *game)
{
	mlx_hook(game->win_p, 17, (1L << 17), &ft_handle_key, &game);
	return ;
}

int	main(int argc, char **argv)
{
	t_solong	game;

	ft_validate(&game, argc, argv[1]);
	ft_mlx_init(&game);
	game.win_y = TILESIZE * 15;
	game.win_x = TILESIZE * 20;
	game.win_p = mlx_new_window(game.mlx, game.win_x, game.win_y, "game window");
	if (game.win_p == NULL)
		ft_close(&game);
	mlx_hook(game.win_p, DestroyNotify, NoEventMask, ft_close, &game);
	mlx_hook(game.win_p, KeyPress, KeyPressMask, ft_handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
