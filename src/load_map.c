/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:09:49 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/15 22:43:22 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_elem(const char *str, char c)
{
	int	res;

	res = 0;
	while (str != NULL && *str)
	{
		if (*str == c)
			++res;
		++str;
	}
	return (res);
}

static t_pair_int	check_size_map(const char *str)
{
	t_pair_int	res;
	char		*str;
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ee_exit("Error: cann't open file\n");
	res.second = 1;
	str = get_next_line(fd);
	res.first = ft_count_elem(str, ' ');
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		++res.second;
	}
	close(fd);
	return (res);
}

void	parse(char *str, char c, int *arr)
{
	int	i;

	i = 0;
	while (*str)
	{
		arr[i++] = ft_atoi(str);
		while (*str != c && *str)
			++str;
		if (*str == '\0')
			break;
		++str;
	}
}

t_matrix	*load_map(const char *name)
{
	t_matrix	*map;
	int			i;
	int			fd;
	char		*str;

	map = init_matrix(check_size_map(name));
	if (map == NULL)
		ee_exit("Error: cann't alloc memory for map\n");
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ee_exit("Error: cann't open file\n");
	i = 0;
	while (i < map->height)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			free_matrix(map);
			map = NULL;
			break;
		}
		parse(str, ' ', map->arr[i++]);
		free(str);
	}
	return (map);
}
