/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:55:07 by jusato            #+#    #+#             */
/*   Updated: 2022/10/03 21:27:08 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include "../libft/libft.h"

# define TILESIZE 32

typedef struct s_imgs
{
	void	*ptr;
	int		x;
	int		y;
}				t_imgs;

typedef struct s_solong
{
	void	*mlx;
	void	*win;
	
	t_imgs	wall;
	t_imgs	grass;
}				t_solong;

#endif
