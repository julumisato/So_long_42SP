/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:27:17 by jusato            #+#    #+#             */
/*   Updated: 2022/09/28 03:06:47 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_and_save(int fd, char *read_line);
static char	*make_return_line(char *read_line);
static char	*clear_and_save_next(char *read_line);

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*ret_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_line = read_and_save(fd, read_line);
	if (!read_line)
		return (NULL);
	ret_line = make_return_line(read_line);
	read_line = clear_and_save_next(read_line);
	return (ret_line);
}

char	*clear_and_save_next(char *read_line)
{
	char	*aux;
	size_t	i;
	size_t	size;

	i = 0;
	while (read_line[i] != '\n' && read_line[i])
		i ++;
	size = ft_strlen(read_line) - i;
	if (size > 0)
	{
		aux = malloc(size + 1 * sizeof(char));
		if (!aux)
			return (NULL);
		ft_strlcpy(aux, &read_line[i + 1], size);
		free(read_line);
		return (aux);
	}
	free(read_line);
	return (NULL);
}

char	*make_return_line(char *read_line)
{
	size_t	i;
	char	*ret_line;

	i = 0;
	if (!read_line[i])
		return (NULL);
	while (read_line[i] != '\n' && read_line[i])
		i ++;
	if (i <= ft_strlen(read_line))
	{
		ret_line = malloc(sizeof(char) * (i + 2));
		if (ret_line == NULL)
			return (NULL);
		ft_strlcpy(ret_line, read_line, i + 2);
		return (ret_line);
	}
	return (NULL);
}

char	*read_and_save(int fd, char *read_line)
{
	int		read_bytes;
	char	*buff;

	read_bytes = BUFFER_SIZE;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(read_line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		read_line = ft_strjoin(read_line, buff);
	}
	free(buff);
	return (read_line);
}
