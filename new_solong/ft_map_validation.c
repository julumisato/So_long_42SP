/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:01:43 by jusato            #+#    #+#             */
/*   Updated: 2022/10/06 07:07:23 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_validation(t_solong *game)
{
	/*
	The map must be constructed with: walls, collectibles and free spaces
	only 5 valid chars: 0 (Empty), 1 (wall), C (collect), E (exit), P(player start position)
	Must contain at least 1 Exit, 1 collectible, 1 start position.
	(must not have duplicated exit/start)
	must be rectangular,
	must be surrounded by walls
	must be a valid path in the map
	
	
	*/
}
