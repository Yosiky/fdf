/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:49:01 by eestelle          #+#    #+#             */
/*   Updated: 2022/04/14 13:31:09 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

t_point	init_point(float x, float y);

#endif
