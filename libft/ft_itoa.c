/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:17:51 by jusato            #+#    #+#             */
/*   Updated: 2022/04/27 22:40:27 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoalen(long int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len ++;
	while (n != 0)
	{
		len ++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	size_t		len;

	num = (long int)n;
	if (num < 0)
		num = num * -1;
	len = ft_itoalen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num == 0)
		*str = '0';
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while (num)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len --;
	}
	return (str);
}
