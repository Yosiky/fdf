/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:41:36 by eestelle          #+#    #+#             */
/*   Updated: 2022/05/17 13:58:30 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z, int l, int h)
{
	float	color;
	int		green;
	int		red;
	int		blue;

	if (h == l)
		return (189 << 8);
	color = (float)(z) / (h - l);
	green = 189 + (6 - 189) * color;
	red = 133 * color;
	blue = 57 + 112 * color;
	return ((red << 16) + (green << 8) + blue);
}
