/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:13:10 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/15 22:49:27 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		img.map = load_map((const char *)argv[1]);
	}
	else
		write(2, "Error: wrong input\nYou need write:\n./fdf [NAME MAP]\n");
	return (0);	
}
