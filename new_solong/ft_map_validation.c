/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:01:43 by jusato            #+#    #+#             */
/*   Updated: 2022/10/07 04:15:04 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				ft_close(game, "There's invalid character in the map! (Allowed chars: '10CEP')");
			if (game->map.mapp[i][j] == 'C')
				game->map.c_n ++;
			if (game->map.mapp[i][j] == 'E')
				game->map.e_n ++;
			if (game->map.mapp[i][j] == 'P')
				game->map.p_n ++;
			j ++;
		}
		i ++;
	}
	return ;
}

void	ft_check_map_elements(t_solong *game)
{
	if (game->map.c_n < 1)
		ft_close(game, "The map have to contain at least one collectible element!");
	if (game->map.e_n != 1)
		ft_close(game, "Only one exit element is allowed!");
	if (game->map.p_n != 1)
		ft_close(game, "Only one Player initial position is allowed!");
	return ;
}

void	*ft_diff_chrstr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != c)
			return (&str[i]);
		i ++;
	}
	return (NULL);
}

void	ft_map_validation(t_solong *game)
{
	int	i;
	/* The map must be constructed with: walls, collectibles and free spaces
	only 5 valid chars: 0 (Empty), 1 (wall), C (collect), E (exit), P(player start position) */
	ft_char_validation(game);
	/* Must contain at least 1 Exit, 1 collectible, 1 start position.
	(must not have duplicated exit/start)*/
	ft_check_map_elements(game);
	/* must be rectangular*/
	if (game->map.rows == game->map.cols)
		ft_close(game, "The map must be rectangular!");
	/* must be surrounded by walls*/
	if (ft_diff_chrstr(game->map.mapp[0], '1') != NULL || ft_diff_chrstr(game->map.mapp[game->map.rows - 1], '1') != NULL)
		ft_close(game, "Map has to be surrounded by walls!");
	i = 1;
	while (i < game->map.rows - 1)
	{
		if (game->map.mapp[i][0] != '1' || game->map.mapp[i][game->map.cols - 1] != '1')
			ft_close(game, "Map has to be surrounded by walls!");
		i ++;
	}
	/*must be a valid path in the map*/
	//ft_check_valid_path(game);
	return ;
}
