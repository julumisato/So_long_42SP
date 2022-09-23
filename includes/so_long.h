/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:55:15 by jusato            #+#    #+#             */
/*   Updated: 2022/09/23 06:09:12 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_____INCLUDES______//

#include <mlx.h>
#include "libft.h"

// Xlib key symbols
#include <X11/keysym.h>

// event names & masks macros
#include <X11/X.h>

//_____DEFINE MACROS___//
# define TILESIZE	32

//_____TYPEDEFS_______//

typedef struct s_win
{
	void	*win_p;
	int		height;
	int		width;
}					t_win;

typedef	struct	s_init
{
	void	*mlx;
	t_win	*window;
}				t_init;

 void	ft_mem_allocate(t_init *game);


#endif
