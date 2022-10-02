/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:36:52 by jusato            #+#    #+#             */
/*   Updated: 2022/10/02 08:00:32 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_alloc_map_memory(t_map *map)
{
	char	**mat;

	map->rows = 10; //ft_count_map_rows();
	mat = malloc((map->rows + 1) * sizeof(char *));
	if (!mat)
		return (NULL);
	return (mat);
}

char	**ft_scan_map(t_map *map, char *map_path)
{
	char	**map_mat;
	int		fd;
	int		i;

	map_mat = ft_alloc_map_memory(map);
	if (!map_mat)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	ft_printf("file is opening\n");
	i = 0;
	while (1)
	{
		map_mat[i] = get_next_line(fd);
		if (!map_mat[i])
			break ;
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
	map_m = NULL;
	// if (map_m == NULL)
	// 	ft_exit(game, "failed to read map!", -1);
	game->map.map = map_m;
	return ;
}
