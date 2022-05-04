/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:58:42 by eestelle          #+#    #+#             */
/*   Updated: 2022/04/29 12:35:40 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# ifdef __linux__
#  include <malloc.h>
# else
#  include <stdlib.h>
# endif

# include <stdint.h>

typedef struct s_pair_int
{
	int	first;
	int	second;
}	t_pair_int;

typedef struct s_matrix
{
	int	width;
	int	height;
	int	*arr;
}	t_matrix;

t_matrix	*init_matrix(t_pair_int size);
void		free_matrix(t_matrix *m);
int			matrix_get(t_matrix *m, int x, int y);
int			matrix_get_min(t_matrix *m);
int			matrix_get_max(t_matrix *m);

#endif
