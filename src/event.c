/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:07:08 by eestelle          #+#    #+#             */
/*   Updated: 2022/04/01 13:58:15 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_window(void)
{
	t_win	*win;

	win = get_window();
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_image(win->mlx, win->img->img);
	free_matrix(win->img->map);
	win->img->map = NULL;
	exit(0);
	return (0);
}

int	key_press(int key)
{
	t_win	*win;

	if (key == KEY_ESC)
		ft_close_window();
	win = get_window();
	if (key == W_BUTTON)
		win->pos->y -= 10;
	else if (key == S_BUTTON)
		win->pos->y += 10;
	else if (key == D_BUTTON)
		win->pos->x += 10;
	else if (key == A_BUTTON)
		win->pos->x -= 10;

	//draw(win->img, win->pos);
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, win->pos->x, win->pos->y);
	return (0);
}

//void	ft_button_press()
