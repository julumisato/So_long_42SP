/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 04:02:26 by jusato            #+#    #+#             */
/*   Updated: 2022/10/10 04:18:52 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_holder;
	t_list	*element;

	if (!*lst)
		return ;
	element = *lst;
	while (element)
	{
		lst_holder = element->next;
		ft_lstdelone(element, del);
		element = lst_holder;
	}
	*lst = NULL;
}
