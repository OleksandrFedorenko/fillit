/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:53:41 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/14 16:53:41 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_size(uint16_t max)
{
	int		size;

	size = 4;
	while (size && !(max & 0x1000))
	{
		max >>= 1;
		size--;
	}
	return (size);
}

void		putinlst(t_tetrimino *copy)
{
	int			i;
	uint16_t	mask;

	mask = 0xF000;
	i = 0;
	while (i < 4)
	{
		copy->bits.pie[i] = (copy->tetr & mask) << (i * 4);
		if (copy->bits.pie[i])
		{
			copy->height++;
			copy->width = ft_max(copy->width, get_size(copy->bits.pie[i]));
		}
		mask >>= 4;
		++i;
	}
}

void		maketetrimino(char *tetrimino, t_tetrimino *copy)
{
	char		*buf;
	char		**table;
	int			i;

	table = ft_strsplit(tetrimino, '\n');
	buf = ft_strnew(16);
	i = 0;
	while (table[i])
	{
		ft_strcpy(buf + (i * 4), table[i]);
		i++;
	}
	ft_free(&table);
	copy->tetr = tobinary(buf);
	copy->patid = checkid(copy->tetr);
	ft_strdel(&buf);
	putinlst(copy);
}

void		put_buff(char *buff, t_map *map)
{
	char		**mem;
	char		**tab;
	int			index;

	mem = ft_strsplit(buff, '@');
	tab = mem;
	index = 0;
	while (*tab)
	{
		maketetrimino(*tab, &map->copy[index]);
		tab++;
		index++;
	}
	ft_free(&mem);
	map->copy_count = index;
}
