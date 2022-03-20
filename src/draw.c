/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:09 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/20 10:57:45 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpixel(t_data *img, int x, int y, unsigned int col)
{
	img->addr[y * img->line_length + x * (img->bits_per_pixel / 8)] = col;
	// move img->bits_per_pixel / 8
}

int		choice_color(t_data *img, int x, int y)
{
	x /= 10;
	y /= 10;
	if (x < 0 || y < 0 || x >= img->map->width || y >= img->map->height)
		return (COLOR_BACKGROUND);
	if (matrix_get(img->map, x, y) > 0)
		return (COLOR_RED);
	if (matrix_get(img->map, x, y) < 0)
		return (COLOR_BLUE);
	else
		return (COLOR_WHITE);
}

void	draw_line(t_point a, t_point b, t_position *pos, t_data *img)
{
	t_point	d;
	int		color;

	color = COLOR_WHITE;
	d = init_point(b.x - a.x, b.y - a.y);
	d.x /= MAX(abs((int)d.x), abs((int)d.y));
	d.y /= MAX(abs((int)d.x), abs((int)d.y));
	a.x += pos->x;
	b.x += pos->x;
	a.y += pos->y;
	b.y += pos->y;
	while (a.x < b.x)
	{
		putpixel(img, a.x, a.y, color);
		a.x += d.x;
		d.y += d.y;
	}
}

void	draw(t_data *img, t_position *pos)
{
	int	i;
	int	j;

	i = -1;
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
