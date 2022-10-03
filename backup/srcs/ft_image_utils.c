/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:52:27 by jusato            #+#    #+#             */
/*   Updated: 2022/10/03 21:58:40 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_images(t_solong *game)
{
	void	*img;
	int		x;
	int		y;

	//img = ft_calloc(1, sizeof(void *));
	img = mlx_xpm_file_to_image(&game->mlx, "assets/img.xpm", &x, &y);
	if (!img)
		ft_printf("\n\n!! NULL img !!\n\n");
	//free(img);
	//imgs->wall.px = mlx_get_data_addr(imgs->wall.ptr, &imgs->wall.bpp, &imgs->wall.l_size, &imgs->wall.endian);
	//imgs->grass.ptr = mlx_xpm_file_to_image(mlx, GRASS_PATH, &imgs->x, &imgs->y);
	//if (imgs->grass.ptr == NULL)
		//ft_printf("no success loading grass img\n");
}

void	ft_print_images(t_solong *game)
{
	if(game->win_p)
		mlx_put_image_to_window(game->mlx, game->win_p, game->imgs.wall.ptr, TILESIZE, TILESIZE);
	// int	xi;
	// int	yi;

	// yi = 0;
	// while (yi < game->map.rows)
	// {
	// 	xi = 0;
	// 	while (xi < game->map.columns)
	// 	{
	// 		mlx_put_image_to_window(game->mlx, game->win_p, game->imgs.grass.ptr, xi * TILESIZE, yi * TILESIZE);
	// 		xi ++;
	// 	}
	// 	yi ++;
	// }
	// return ;
}
