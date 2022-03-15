/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:38:07 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 18:38:08 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *_new)
{
	t_list	*iter;

	if (*lst == (void *)0)
		*lst = _new;
	else
	{
		iter = *lst;
		while (iter->next != (void *)0)
			iter = iter->next;
		iter->next = _new;
	}
}
