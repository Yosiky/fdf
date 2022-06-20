/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:41:36 by eestelle          #+#    #+#             */
/*   Updated: 2022/06/20 17:46:07 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	float	color;
	int		green;
	int		red;
	int		blue;

	if (matrix_get_max(NULL) == matrix_get_min(NULL))
		return (189 << 8);
	color = (float)abs(z - matrix_get_min(NULL)) / abs(matrix_get_max(NULL) - matrix_get_min(NULL));
	green = 189 - 183 * color;
	red = 133 * color;
	blue = 57 + 112 * color;
	return ((red << 16) + (green << 8) + blue);
}
