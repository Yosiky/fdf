/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:09 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/20 00:25:26 by eestelle         ###   ########.fr       */
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


void	draw(t_data *img, __attribute__((unused))t_position *pos)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			color = choice_color(img, i - pos->y, j - pos->x);
			putpixel(img, i, j, color);
		}
	}
}
