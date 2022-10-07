/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:55:07 by jusato            #+#    #+#             */
/*   Updated: 2022/10/07 05:09:12 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h> // for exit() function
//# include "../minilibx/mlx.h"
# include "../libft/libft.h"

// Xlib key symbols
# include <X11/keysym.h>

// event names & masks macros
# include <X11/X.h>

// open function includes
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define TILESIZE 32
# define WALL_PATH "assets/wall.xpm"
# define GRASS_PATH "assets/grass.xpm"
# define PLAYER_PATH "assets/player.xpm"
# define COLLECT_PATH "assets/collect.xpm"
# define GOAL_PATH "assets/goal.xpm"
# define VALID_CHAR "10CEP"

typedef struct s_util
{
	void	*ptr;
	int		x;
	int		y;
}				t_util;

typedef struct s_imgs
{
	int		init;
	t_util	wall;
	t_util	grass;
	t_util	player;
	int		player_x;
	int		player_y;
	t_util	collect;
	t_util	goal;
}				t_imgs;

typedef struct s_map
{
	char	**mapp;
	int		rows;
	int		cols;
	int		init;
	int		c_n;
	int		e_n;
	int		p_n;
}				t_map;

typedef struct s_solong
{
	void	*mlx;
	void	*win;
	int		init;
	int		win_x;
	int		win_y;
	t_map	map;
	t_imgs	imgs;
}				t_solong;

/*         so_long.c              */
void	ft_init_variables(t_solong *game);

/*         ft_init_game.c         */
int		ft_init_game(t_solong *game, int argc, char **argv);
int		ft_mlx_and_window_init(t_solong *game);
void	ft_print_map(t_solong *game);
int		ft_get_images(t_solong *game);

/*         ft_map_init.c          */
void	ft_init_map(t_solong *game, int argc, char **argv);
char	**ft_scan_map(t_solong *game, char *map_path);
char	**ft_alloc_map_memory(t_solong *game, char *path);
void	ft_count_map_size(t_solong *game, char *path);

/*         ft_map_init.c          */
void	ft_map_validation(t_solong *game);
void	ft_check_map_elements(t_solong *game);
void	ft_char_validation(t_solong *game);

/*         ft_hook_utils.c        */
void	ft_define_hooks(t_solong *game);
int		ft_handle_key(int key, t_solong *game);

/*         ft_close_game.c*/
int		ft_close(t_solong *game, char *message);
void	ft_free_map(t_map *map, char **map_mat);

#endif
