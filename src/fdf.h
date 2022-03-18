/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:12:50 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/16 13:25:05 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "matrix.h"
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_data {
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_matrix	*map;
}	t_data;

void		ee_exit(const char *str);
t_matrix	*load_map(const char *name);
void        print_matrix(t_matrix *mas);

#endif
