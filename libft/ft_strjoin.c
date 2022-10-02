/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:00:51 by jusato            #+#    #+#             */
/*   Updated: 2022/09/28 02:41:39 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i ++;
	while (s2[j])
		j ++;
	len = i + j;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	ft_strlcpy(str, s1, i + 1);
	ft_strlcpy(&str[i], s2, j + 1);
	free(s1);
	return (str);
}
