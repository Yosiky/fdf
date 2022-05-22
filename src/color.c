/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:41:36 by eestelle          #+#    #+#             */
/*   Updated: 2022/05/22 16:08:01 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	float	color;
	int		green;
	int		red;
	int		blue;

	if (*(get_high()) == *(get_low()))
		return (189 << 8);
	color = (float)(z) / (*(get_high()) - *(get_low()));
	green = 189 - 183 * color;
	red = 133 * color;
	blue = 57 + 112 * color;
	return ((red << 16) + (green << 8) + blue);
}
