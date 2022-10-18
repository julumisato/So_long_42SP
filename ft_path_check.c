/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:09:40 by jusato            #+#    #+#             */
/*   Updated: 2022/10/18 06:28:45 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_init_check_matrix(t_solong *game)
{
	char	**mat;
	int		i;

	mat = ft_calloc(game->map.rows + 1, sizeof(char *));
	if (!mat)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		mat[i] = ft_calloc(game->map.cols + 1, sizeof(char));
		if (!mat[i])
			return (NULL);
		ft_strlcpy(mat[i], game->map.mapp[i], ft_strlen(game->map.mapp[i]) + 1);
		i ++;
	}
	return (mat);
}

void	ft_check_path(char **check, t_check *pathcheck, int row, int col)
{
	if (!check[row][col] || check[row][col] == 'X')
		return ;
	if (check[row][col] == 'E')
		pathcheck->e_n ++;
	if (check[row][col] == 'C')
		pathcheck->c_n ++;
	if (check[row][col] != '1')
	{
		check[row][col] = 'X';
		ft_check_path(check, pathcheck, row + 1, col);
		ft_check_path(check, pathcheck, row, col + 1);
		ft_check_path(check, pathcheck, row - 1, col);
		ft_check_path(check, pathcheck, row, col - 1);
	}
	return ;
}

int	ft_check_reach(t_map *map, t_check *pathcheck)
{
	if (map->c_n != pathcheck->c_n)
		return (0);
	if (map->e_n != pathcheck->e_n)
		return (0);
	return (1);
}

void	ft_check_valid_path(t_solong *game)
{
	char	**check;
	t_check	pathcheck;

	pathcheck.c_n = 0;
	pathcheck.e_n = 0;
	check = ft_init_check_matrix(game);
	ft_check_path(check, &pathcheck, game->imgs.player_y, game->imgs.player_x);
	ft_free_map(&game->map, check);
	if (!ft_check_reach(&game->map, &pathcheck))
		ft_close(game, "there's no valid path in the map!");
}
