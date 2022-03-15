/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:27:13 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 18:30:07 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*iter;

	result = NULL;
	if (!f)
		return (NULL);
	if (lst)
	{
		result = ft_lstnew((*f)(lst->content));
		if (!result)
			return (NULL);
		iter = result;
		while (lst->next != NULL)
		{
			iter->next = ft_lstnew((*f)(lst->next->content));
			if (!iter->next)
			{
				ft_lstclear(&result, del);
				return (NULL);
			}
			iter = iter->next;
			lst = lst->next;
		}
	}
	return (result);
}
