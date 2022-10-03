/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:39:21 by jusato            #+#    #+#             */
/*   Updated: 2022/04/27 22:36:47 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i ++;
	}
	if (neg)
		return (-nbr);
	else
		return (nbr);
}
