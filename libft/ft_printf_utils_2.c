/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:49:12 by jusato            #+#    #+#             */
/*   Updated: 2022/09/28 03:06:23 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_char(t_printf *param, char c)
{
	int	i;

	i = 0;
	if (param->min > 0)
	{
		if (!param->left_posit)
		{
			while (i++ < param->min - 1)
				param->ret += write(1, " ", 1);
		}
		param->ret += write(1, &c, 1);
		if (param->left_posit)
		{
			while (i++ < param->min - 1)
				param->ret += write(1, " ", 1);
		}
	}
	else
		param->ret += write(1, &c, 1);
	return ;
}

void	ft_printf_num(t_printf *param, int value)
{
	int	i;

	if (value >= 0)
	{
		if (param->space)
			param->ret += write(1, " ", 1);
		else if (param->signal)
			param->ret += write(1, "+", 1);
	}
	i = 0;
	if (!param->left_posit && param->min > ft_numlen(value))
		while (i++ < (param->min - ft_numlen(value)))
			param->ret += write(1, " ", 1);
	ft_putnbr_fd(value, 1);
	if (param->left_posit && param->min > ft_numlen(value))
		while (i++ < (param->min - ft_numlen(value)))
			param->ret += write(1, " ", 1);
	param->ret += ft_numlen(value);
}

void	ft_printf_str_width(t_printf *param, char *str)
{
	int	i;

	i = 0;
	if (!param->left_posit && param->min > (int)ft_strlen(str))
		while (i++ < (param->min - (int)ft_strlen(str)))
			param->ret += write(1, " ", 1);
	ft_putstr_fd(str, 1);
	if (param->left_posit && param->min > (int)ft_strlen(str))
		while (i++ < (param->min - (int)ft_strlen(str)))
			param->ret += write(1, " ", 1);
	param->ret += ft_strlen(str);
	return ;
}

void	ft_printf_ptr_width(t_printf *param, char *str)
{
	int	i;

	i = 0;
	param->min -= 2;
	if (!param->left_posit && param->min > (int)ft_strlen(str))
		while (i++ < (param->min - (int)ft_strlen(str)))
			param->ret += write(1, " ", 1);
	param->ret += (write(1, "0x", 2));
	ft_putstr_fd(str, 1);
	param->ret += ft_strlen(str);
	if (param->left_posit && param->min > (int)ft_strlen(str))
		while (i++ < (param->min - (int)ft_strlen(str)))
			param->ret += write(1, " ", 1);
	return ;
}
