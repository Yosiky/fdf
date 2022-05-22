/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:12:50 by eestelle          #+#    #+#             */
/*   Updated: 2022/05/22 15:29:36 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <sys/param.h>
# include "matrix.h"
# include "point.h"
# include "event.h"
# include <stdint.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

# define PI 3.1415953565
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800

# define COLOR_BACKGROUND 0x00000000
# define COLOR_BLUE 0x000000FF
# define COLOR_RED 0x00FF0000
# define COLOR_WHITE 0xFFFFFFFF

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
	int				x;
	int				y;
	int				z;
	float			angle[3];
	long long		zoom;
}	t_position;

typedef struct s_win
{
	void		*win;
	void		*mlx;
	t_data		*img;
	t_position	*pos;
}	t_win;

ssize_t		write(int fd, const void *__restrict data, size_t size);
void		ee_exit(const char *str);
t_matrix	*load_map(const char *name);
void		print_matrix(t_matrix *mas);
void		draw(t_data *img, t_position *pos);
int			ft_close_window(void);
int			key_press(int key);
t_win		*get_window(void);
int			get_color(int z);
int			*get_low(void);
int			*get_high(void);

#endif
