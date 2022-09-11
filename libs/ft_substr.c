/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:01:58 by jusato            #+#    #+#             */
/*   Updated: 2022/04/29 21:06:42 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	ss_len;

	if (s == NULL)
		return (NULL);
	if (start < ft_strlen(s))
	{
		ss_len = ft_strlen(s) - start;
		if (ss_len <= len)
			substr = (char *)malloc((ss_len + 1) * sizeof(char));
		else
			substr = (char *)malloc((len + 1) * sizeof(char));
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, &s[start], len + 1);
	}
	else
		substr = (char *)ft_calloc(1, sizeof(char));
	return (substr);
}
