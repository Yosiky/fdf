/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:12:50 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/18 17:35:19 by eestelle         ###   ########.fr       */
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

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

typedef struct s_data
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_matrix	*map;
}	t_data;

typedef struct s_position
{
	int	x;
	int	y;
	int	z;
	int	angle[3];
}	t_position;

void		ee_exit(const char *str);
t_matrix	*load_map(const char *name);
void        print_matrix(t_matrix *mas);

#endif
