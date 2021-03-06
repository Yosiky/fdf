/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:13:10 by eestelle          #+#    #+#             */
/*   Updated: 2022/06/20 17:58:43 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_pos(t_position *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
	a->zoom = 20;
}

void	init(t_win *win, t_data *img, t_position *pos)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	img->img = mlx_new_image(win->mlx, WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2);
	img->addr = (int *)mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	win->img = img;
	win->pos = pos;
	mlx_hook(win->win, 17, 0, ft_close_window, NULL);
	mlx_key_hook(win->win, key_press, NULL);
	matrix_get_min(img->map);
	matrix_get_max(img->map);
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
		init_pos(&pos);
		init(win, &img, &pos);
		draw(&img, &pos);
		mlx_put_image_to_window(win->mlx, win->win, img.img,
			win->pos->x, win->pos->y);
		mlx_loop(win->mlx);
	}
	else
		ee_exit("Error: wrong input\nYou need write:\n./fdf [NAME MAP]\n");
	return (0);
}
