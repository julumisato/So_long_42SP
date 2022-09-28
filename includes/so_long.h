/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:55:15 by jusato            #+#    #+#             */
/*   Updated: 2022/09/28 04:21:04 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_____INCLUDES______//

#include <mlx.h>
#include "../libs/libft.h"

// Xlib key symbols
#include <X11/keysym.h>

// event names & masks macros
#include <X11/X.h>

// open function
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//_____DEFINE MACROS___//
# define TILESIZE	32

//_____TYPEDEFS_______//

typedef struct s_map
{
	void	*map_p;
}				t_map;

typedef	struct	s_solong
{
	void	*mlx;

	void	*win_p;
	int		win_x;
	int		win_y;

	int		map_x;
	int		map_y;
}				t_solong;

#endif
