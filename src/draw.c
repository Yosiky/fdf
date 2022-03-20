/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:09 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/20 11:54:59 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpixel(t_data *img, int x, int y, unsigned int col)
{
	img->addr[y * img->line_length / 4 + x] = col;
	// move img->bits_per_pixel / 8
}

void	draw_line(t_point a, t_point b, t_position *pos, t_data *img)
{
	t_point	d;
	int		color;
	int		m;

	color = COLOR_WHITE;
	d = init_point(b.x - a.x, b.y - a.y);
	m = MAX(abs((int)d.x), abs((int)d.y));
	d.x /= m;
	d.y /= m;
	a.x += pos->x;
	b.x += pos->x;
	a.y += pos->y;
	b.y += pos->y;
	while (a.x < b.x)
	{
		putpixel(img, a.x, a.y, color);
		a.x += d.x;
		a.y += d.y;
	}
}

void	draw(t_data *img, t_position *pos)
{
	int	i;
	int	j;

	i = -1;
	draw_line(init_point(0, 0), init_point(100, 100), pos, img);
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
