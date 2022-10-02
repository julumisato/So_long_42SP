/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 06:56:47 by jusato            #+#    #+#             */
/*   Updated: 2022/05/09 03:37:06 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j] && str2[j] && i + j < n)
			j ++;
		if (str2[j] == '\0')
			return ((char *) str1 + i);
		i ++;
	}
	return (NULL);
}
