/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:49:53 by jusato            #+#    #+#             */
/*   Updated: 2022/04/27 22:35:51 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char *s, char c);
static void		*ft_free(char **array);
static char		**ft_makearray(const char *s, char c, char **array);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	count_words;

	if (s == NULL || !ft_isascii(c))
		return (NULL);
	count_words = ft_countwords((char *)s, c);
	array = (char **)malloc((count_words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s && *s == c)
		s ++;
	if (count_words > 0)
		array = ft_makearray((char *)s, c, array);
	array[count_words] = NULL;
	return (array);
}

static size_t	ft_countwords(char *s, char c)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (count);
	while (*s == c && *s)
		s ++;
	while (*s)
	{
		count ++;
		while (*s && *s != c)
			s ++;
		while (*s && *s == c)
			s ++;
	}
	return (count);
}

static void	*ft_free(char **array)
{
	while (*array)
		free(*array);
	free (array);
	return (NULL);
}

static char	**ft_makearray(const char *s, char c, char **array)
{
	size_t	size;
	size_t	i;

	i = 0;
	while (*s)
	{
		size = 0;
		while (s[size] && s[size] != c)
			size ++;
		array[i] = (char *)malloc((size + 1) * sizeof(char));
		if (array[i] == NULL)
			return (ft_free(array));
		array[i][size] = '\0';
		while (size > 0)
		{
			array[i][size -1] = s[size -1];
			size --;
		}
		while (*s && *s != c)
			s ++;
		while (*s && *s == c)
			s ++;
		i ++;
	}
	return (array);
}
