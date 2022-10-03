/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:08:38 by jusato            #+#    #+#             */
/*   Updated: 2022/04/12 19:40:05 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*trim;

	trim = NULL;
	if (s1 != NULL && set != NULL)
	{
		front = 0;
		back = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front ++;
		while (s1[back - 1] && ft_strchr(set, s1[back -1]) && back > front)
			back --;
		trim = (char *)malloc(1 * (back - front + 1));
		if (trim)
			ft_strlcpy(trim, &s1[front], back - front + 1);
	}
	return (trim);
}
