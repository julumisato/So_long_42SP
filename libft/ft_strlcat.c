/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:18:13 by jusato            #+#    #+#             */
/*   Updated: 2022/04/15 21:43:11 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;
	size_t	ret;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	i = 0;
	if (size > len_d)
	{
		ret = len_s + len_d;
		while (src[i] && len_d < size - 1)
			dest[len_d++] = src[i++];
		dest[len_d] = '\0';
		return (ret);
	}
	else
		return (len_s + size);
}
