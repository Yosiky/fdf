/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:38:37 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 18:38:39 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iter;

	while (*lst != NULL)
	{
		iter = *lst;
		(*del)(iter->content);
		(*lst) = (*lst)->next;
		free(iter);
	}
}
