/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:07:08 by eestelle          #+#    #+#             */
/*   Updated: 2022/04/01 13:40:26 by eestelle         ###   ########.fr       */
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
	if (key == KEY_ESC)
		ft_close_window();
	return (0);
}

//void	ft_button_press()
