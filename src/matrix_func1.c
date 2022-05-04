/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:53 by eestelle          #+#    #+#             */
/*   Updated: 2022/04/29 12:52:00 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	free_matrix(t_matrix *m)
{
	if (m == NULL)
		return ;
	free(m->arr);
	free(m);
}

t_matrix	*init_matrix(t_pair_int size)
{
	t_matrix	*res;

	res = (t_matrix *)malloc(sizeof(t_matrix));
	if (res == NULL)
		return (NULL);
	res->width = size.first;
	res->height = size.second;
	res->arr = (int *)malloc(sizeof(int) * res->height * res->width);
	if (res->arr == NULL)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

int	matrix_get(t_matrix *m, int x, int y)
{
	return (m->arr[y * m->width + x]);
}

int	matrix_get_min(t_matrix *m)
{
	int		res;
	int		i;
	int64_t	len;

	m->arr[0];
	i = 1;
	len = m->width * m->height;
	while (i < len)
	{
		if (res < m->arr[i])
			res = m->arr[i];
		++i;
	}
	return (res);
}

int	matrix_get_max(t_matrix *m)
{
	int		res;
	int		i;
	int64_t	len;

	m->arr[0];
	i = 1;
	len = m->width * m->height;
	while (i < len)
	{
		if (res > m->arr[i])
			res = m->arr[i];
		++i;
	}
	return (res);
}
