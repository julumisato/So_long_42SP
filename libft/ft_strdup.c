/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:02:02 by jusato            #+#    #+#             */
/*   Updated: 2022/04/14 20:21:34 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(src) + 1) * 1);
	i = 0;
	while (*src)
	{
		dest[i] = *src;
		src ++;
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}
