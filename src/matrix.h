/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:58:42 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/15 22:05:42 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# ifdef __linux__
#  include <malloc.h>
# else
#  include <stdlib.h>
# endif

typedef	struct s_pair_int
{
	int	first;
	int	second;
}	t_pair_int;

typedef struct s_matrix
{
	int	width;
	int	height;
	int	**arr;
}	t_matrix;

t_matrix	*init_matrix(t_pair_int size);
void		free_matrix(void);

#endif
