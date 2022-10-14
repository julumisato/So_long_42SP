/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:01:43 by jusato            #+#    #+#             */
/*   Updated: 2022/10/14 06:16:50 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_validation(t_solong *game)
{
	int	i;

	ft_char_validation(game);
	ft_check_map_elements(game);
	if (game->map.rows == game->map.cols)
		ft_close(game, "The map must be rectangular!");
	if (ft_diff_chrstr(game->map.mapp[0], '1') != NULL
		|| ft_diff_chrstr(game->map.mapp[game->map.rows - 1], '1') != NULL)
		ft_close(game, "Map has to be surrounded by walls!");
	i = 1;
	while (i < game->map.rows - 1)
	{
		if (game->map.mapp[i][0] != '1' ||
			game->map.mapp[i][game->map.cols - 1] != '1')
			ft_close(game, "Map has to be surrounded by walls!");
		i ++;
	}
	//ft_check_valid_path(game);
	return ;
}

void	ft_check_map_elements(t_solong *game)
{
	if (game->map.c_n < 1)
		ft_close(game, "The map has contain at least one collectible element!");
	if (game->map.e_n != 1)
		ft_close(game, "Only one exit element is allowed!");
	if (game->map.p_n != 1)
		ft_close(game, "Only one Player initial position is allowed!");
	return ;
}

void	ft_char_validation(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (!ft_strchr(VALID_CHAR, game->map.mapp[i][j]))
				ft_close(game, "Invalid char in the map! (Allowed: '10CEP')");
			if (game->map.mapp[i][j] == 'C')
				game->map.c_n ++;
			if (game->map.mapp[i][j] == 'E')
				game->map.e_n ++;
			if (game->map.mapp[i][j] == 'P')
			{
				game->map.p_n ++;
				game->imgs.player_x = j;
				game->imgs.player_y = i;
			}
			j ++;
		}
		i ++;
	}
}
