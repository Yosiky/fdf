/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:53 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/15 22:33:31 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	free_matrix(t_matrix *m)
{
	if (m == NULL)
		return ;
	if (m->arr != NULL)
	{
		while (m->height-- > 0)
			free(m->arr[m->height]);
	}
	free(m->arr);
	free(m);
}

static int	check_malloc(int **m, int len)
{
	while (len-- > 0)
		if (m[len] == NULL)
			return (1);
	return (0);
}

t_matrix	*init_matrix(t_pair_int size)
{
	t_matrix	*res;

	res = (t_matrix *)malloc(sizeof(t_matrix));
	if (res == NULL)
		return (NULL);
	res->width = size.first;
	res->height = size.second;
	res->arr = (int **)malloc(sizeof(int *) * res->height);
	if (res->arr == NULL)
	{
		free_matrix(res);
		return (NULL);
	}
	while (size.second-- > 0)
		res->arr[size.second] = (int *)malloc(sizeof(int) * size.first);
	if (check_malloc(res->arr, res->height))
	{
		free_matrix(res);
		return (NULL);
	}
	return (res);
}
