/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:13:10 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/18 16:02:59 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
void	print_matrix(t_matrix *map)
{
	printf("MAP:\n");
	printf("width = %d\n", map->width);
	printf("height = %d\n", map->height);
	for (int i = 0; i < map->height; ++i)
	{
		for (int j = 0; j < map->width; ++j)
		{
			printf("\t%d", *(map->arr + i * map->height + j));
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		img.map = load_map((const char *)argv[1]);
		if (img.map == NULL)
			ee_exit("Error: failed to allocate memory for the card\n");
		//print_matrix(img.map);
	    free_matrix(img.map);
    }
	else
		ee_exit("Error: wrong input\nYou need write:\n./fdf [NAME MAP]\n");
	return (0);	
}
