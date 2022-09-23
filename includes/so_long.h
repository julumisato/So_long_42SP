/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:55:15 by jusato            #+#    #+#             */
/*   Updated: 2022/09/23 04:03:03 by jusato           ###   ########.fr       */
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

//_____TYPEDEFS_______//
typedef	struct	s_init
{
	void	*mlx;
	void	*win;
}				t_init;

 void	ft_mem_allocate(t_init *game);

#endif
