/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:09 by eestelle          #+#    #+#             */
/*   Updated: 2022/06/20 17:14:26 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpixel(t_data *img, int x, int y, unsigned int col)
{
	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
		return ;
	img->addr[(y + 10) * img->line_length / 4 + x + 10] = col;
}

void	offset(t_point *a, int z, t_position *pos)
{
	static int	width3 = WINDOW_WIDTH / 3;
	static int	height3 = WINDOW_HEIGHT / 3;

	a->x *= pos->zoom;
	a->y *= pos->zoom;
	a->x = (a->x - a->y);
	a->y = (a->x + a->y + a->y) / 2 - z * pos->zoom / 20;
	a->x += pos->x + width3;
	a->y += pos->y + height3;
}

void	draw_line(t_point a, t_point b, t_position *pos, t_data *img)
{
	t_point	d;
	int		m;
	t_point	z;

	z = init_point(matrix_get(img->map, a.x, a.y),
			matrix_get(img->map, b.x, b.y));
	offset(&a, z.x, pos);
	offset(&b, z.y, pos);
	d = init_point(b.x - a.x, b.y - a.y);
	m = MAX(abs((int)d.x), abs((int)d.y));
	d.x /= m;
	d.y /= m;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		putpixel(img, a.x, a.y, get_color(z.x));
		a.x += d.x;
		a.y += d.y;
		if (a.x < 0 || a.y < 0 || a.x > WINDOW_WIDTH || a.y > WINDOW_HEIGHT)
			break ;
	}
}

void	draw(t_data *img, t_position *pos)
{
	int	i;
	int	j;

	i = -1;
	ft_memset(img->addr, 0, WINDOW_HEIGHT * WINDOW_HEIGHT * 4 * 4);
	while (++i < img->map->width)
	{
		j = -1;
		while (++j < img->map->height)
		{
			if (i < img->map->width - 1)
				draw_line(init_point(i, j), init_point(i + 1, j), pos, img);
			if (j < img->map->height - 1)
				draw_line(init_point(i, j), init_point(i, j + 1), pos, img);
		}
	}
}
