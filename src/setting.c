/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:52:08 by eestelle          #+#    #+#             */
/*   Updated: 2022/05/22 15:08:27 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*get_low(void)
{
	static int	l;

	return (&l);
}

int	*get_high(void)
{
	static int	h;

	return (&h);
}