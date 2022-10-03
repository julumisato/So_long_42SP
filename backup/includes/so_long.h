/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:55:15 by jusato            #+#    #+#             */
/*   Updated: 2022/10/03 06:49:15 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_____INCLUDES______//

# include <mlx.h>
# include "../libft/libft.h"

// Xlib key symbols
# include <X11/keysym.h>

// event names & masks macros
# include <X11/X.h>

// open function
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//_____DEFINE MACROS___//
# define TILESIZE	32


//______IMAGE PATHS____//
# define WALL_PATH "assets/wall.xpm"
# define GRASS_PATH "assets/grass.xpm"

//_____TYPEDEFS_______//

typedef struct s_map
{
	char	**map;
	// int		map_x;
	// int		map_y;
	int		rows;
	int		columns;
}				t_map;

typedef struct s_src
{
	void	*ptr;
	//int		sizex;
	//int		sizey;
	// char	*px;
	// int		bpp;
	// int		l_size;
	// int		endian;
	// int		positx;
	// int		posity;
}				t_src;

typedef struct s_imgs
{
	t_src	wall;
	t_src	grass;
	int		x;
	int		y;
}				t_imgs;

typedef struct s_solong
{
	void	*mlx;

	void	*win_p;
	int		win_x;
	int		win_y;

	t_map	map;
	t_imgs	imgs;
}				t_solong;

// initialization 
void	ft_init_variables(t_solong *game);

int		ft_init_game(t_solong *game, int argc, char **argv);
void	ft_init_map(t_solong *game, int argc, char **argv);
int		ft_mlx_and_window_init(t_solong *game);

char	**ft_scan_map(t_solong *game, char *map_path);
char	**ft_alloc_map_memory(t_solong *game, char *path);
void	ft_count_map_size(t_solong *game, char *path);

void	ft_init_images(t_solong *game);
void	ft_print_images(t_solong *game);


// hooking utils
int		ft_handle_key(int key, t_solong *game);

// finalization utils
int		ft_close(t_solong *game);
void	ft_free_ptr(void **ptr);
void	ft_free_map(t_map *map, char **map_mat);
void	ft_exit(t_solong *game, char *message);

#endif
