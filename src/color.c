/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:41:36 by eestelle          #+#    #+#             */
/*   Updated: 2022/05/04 18:34:45 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z, int l, int h)
{

	float	color = (float)z / (h - l);
	int		green = 189 + (6 - 189) * color;// + (222 - 241) * color;
	int		red = 0 + (133 - 0) * color;
	int		blue = 57 + (169 - 57) * color;

	return ((red << 16) + (green << 8) + blue);
}
