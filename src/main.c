/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:13:10 by eestelle          #+#    #+#             */
/*   Updated: 2022/04/01 13:32:20 by eestelle         ###   ########.fr       */
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
	a->x = 200;
	a->y = 200;
	a->z = 0;
	a->angle[0] = 0.8;
	a->angle[1] = 0;
	a->angle[2] = 0;
	a->zoom = 20;
}

void	init(t_win *win, t_data *img, t_position *pos)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	img->img = mlx_new_image(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,&img->endian);
	win->img = img;
	win->pos = pos;
	mlx_hook(win->win, 33, 0, ft_close_window, NULL);

}

t_win	*get_window(void)
{
	static t_win	win;

	return (&win);
}

int	main(int argc, char **argv)
{
	t_win		*win;
	t_data		img;
	t_position	pos;

	if (argc == 2)
	{
		win = get_window();
		img.map = load_map((const char *)argv[1]);
		if (img.map == NULL)
			ee_exit("Error: failed to allocate memory for the card\n");
		print_matrix(img.map);
		init_pos(&pos);
		init(win, &img, &pos);
		draw(&img, &pos);
		mlx_put_image_to_window(win->mlx, win->win, img.img, 0, 0);
		mlx_loop(win->mlx);
	    //free_matrix(img.map);
    }
	else
		ee_exit("Error: wrong input\nYou need write:\n./fdf [NAME MAP]\n");
	return (0);	
}
