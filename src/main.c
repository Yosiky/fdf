/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:13:10 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/19 17:03:58 by eestelle         ###   ########.fr       */
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
            printf("%3d", *(map->arr + i * map->width + j));
		printf("\n");
	}
}

static void	init_pos(t_position *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
	a->angle[0] = 0;
	a->angle[1] = 0;
	a->angle[2] = 0;
}

int	main(int argc, char **argv)
{
	t_data		img;
	t_position	pos;
	void		*mlx;
	void		*mlx_win;

	if (argc == 2)
	{
		img.map = load_map((const char *)argv[1]);
		if (img.map == NULL)
			ee_exit("Error: failed to allocate memory for the card\n");
		print_matrix(img.map);
		init_pos(&pos);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
		mlx_loop(mlx);
		img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		while (1)
		{
			draw(&img, &pos);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);	
		}
		mlx_loop(mlx);
	    free_matrix(img.map);
    }
	else
		ee_exit("Error: wrong input\nYou need write:\n./fdf [NAME MAP]\n");
	return (0);	
}
