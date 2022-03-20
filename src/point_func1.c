/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:49:14 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/20 10:52:43 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	init_point(float x, float y)
{
	t_point res;

	res.x = x;
	res.y = y;
	return (res);
}