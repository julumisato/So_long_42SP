/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:00:51 by jusato            #+#    #+#             */
/*   Updated: 2022/05/09 04:24:11 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc (1 * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && *s1)
	{
		str[i] = *s1;
		s1 ++;
		i ++;
	}
	while (i < len && *s2)
	{
		str[i] = *s2;
		s2 ++;
		i ++;
	}
	str[i] = '\0';
	if (str == NULL)
		return (NULL);
	return (str);
}
