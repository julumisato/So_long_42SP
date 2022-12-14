/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:20:10 by jusato            #+#    #+#             */
/*   Updated: 2022/10/14 06:14:26 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_solong *game, int argc, char **argv)
{
	char	**map_m;

	if (argc != 2)
		ft_close(game, "Please input only one map path argument.");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		ft_close(game, "Invalid map format! only '.ber' permitted.");
	map_m = ft_scan_map(game, argv[1]);
	if (!map_m)
		ft_close(game, "Failed to read map! File not found.");
	game->map.mapp = map_m;
	game->map.init ++;
	ft_map_validation(game);
	return ;
}

char	**ft_scan_map(t_solong *game, char *map_path)
{
	char	**map_mat;
	char	*aux;
	int		fd;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_close(game, "Failed to open file.");
	map_mat = ft_alloc_map_memory(game, map_path);
	if (!map_mat)
		return (NULL);
	i = 0;
	while (1)
	{
		aux = get_next_line(fd);
		if (!aux)
			break ;
		ft_strlcpy(map_mat[i], aux, game->map.cols + 1);
		free(aux);
		i ++;
	}
	map_mat[i] = NULL;
	close (fd);
	return (map_mat);
}

char	**ft_alloc_map_memory(t_solong *game, char *path)
{
	char	**mat;
	int		i;

	ft_count_map_size(game, path);
	mat = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!mat)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		mat[i] = ft_calloc(game->map.cols + 1, sizeof(char));
		if (!mat[i])
			return (NULL);
		i ++;
	}
	mat[i] = NULL;
	return (mat);
}

void	ft_count_map_size(t_solong *game, char *path)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(path, O_RDONLY);
	rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->map.cols == 0)
			game->map.cols = ft_strlen(line) - 1;
		free(line);
		rows ++;
	}
	game->map.rows = rows;
	close (fd);
	return ;
}
