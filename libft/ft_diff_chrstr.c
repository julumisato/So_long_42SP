/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff_chrstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:26:49 by jusato            #+#    #+#             */
/*   Updated: 2022/10/07 04:27:15 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_diff_chrstr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != c)
			return (&str[i]);
		i ++;
	}
	return (NULL);
}
