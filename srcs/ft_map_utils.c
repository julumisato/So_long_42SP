/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:36:52 by jusato            #+#    #+#             */
/*   Updated: 2022/10/02 09:01:10 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_map_rows(char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		free(line);
		count ++;
	}
	close (fd);
	return (count);
}

char	**ft_alloc_map_memory(t_map *map, char *path)
{
	char	**mat;

	map->rows = ft_count_map_rows(path);
	mat = malloc((map->rows + 1) * sizeof(char *));
	if (!mat)
		return (NULL);
	return (mat);
}

char	**ft_scan_map(t_map *map, char *map_path)
{
	char	**map_mat;
	char	*aux;
	int		fd;
	int		i;

	map_mat = ft_alloc_map_memory(map, map_path);
	if (!map_mat)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (1)
	{
		aux = get_next_line(fd);
		if (!aux)
			break ;
		map_mat[i] = aux;
		free(aux);
		i ++;
	}
	map_mat[i] = NULL;
	close (fd);
	return (map_mat);
}

void	ft_init_map(t_solong *game, int argc, char **argv)
{
	char	**map_m;

	if (argc != 2)
		exit (1);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		ft_exit(game, "Invalid map!\n", -1);
	map_m = ft_scan_map(&game->map, argv[1]);
	if (map_m == NULL)
		ft_exit(game, "failed to read map!", -1);
	game->map.map = map_m;
	free(map_m);
	return ;
}
