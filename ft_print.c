/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:44:56 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/15 14:44:58 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	letter(char *table, int map_size, t_tetrimino *copy, int number)
{
	int			i;
	int			j;
	uint16_t	tmp_tetr;
	int			index;

	i = 0;
	while (i < copy->height)
	{
		j = 0;
		tmp_tetr = copy->bits.pie[i];
		while (j < copy->width)
		{
			if (tmp_tetr & (0x1 << 15))
			{
				index = (copy->done.y + i) * (map_size + 1)
				+ (copy->done.x + j);
				table[index] = 'A' + number;
			}
			tmp_tetr <<= 1;
			j++;
		}
		i++;
	}
}

void	print_map(t_map *map)
{
	int			i;
	int			number;
	char		*table;
	int			map_size;

	map_size = (map->size + 1) * map->size;
	table = (char *)ft_strnew(map_size * sizeof(char));
	ft_memset(table, '.', map_size);
	i = 0;
	while (i < map->size)
	{
		table[(i + 1) * (map->size + 1) - 1] = '\n';
		i++;
	}
	number = 0;
	while (number < map->copy_count)
	{
		letter(table, map->size, &map->copy[number], number);
		number++;
	}
	ft_putstr(table);
}
