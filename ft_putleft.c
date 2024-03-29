/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:55:48 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/14 16:55:48 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint16_t		tobinary(char *buf)
{
	int			i;
	uint16_t	tetr;

	tetr = 0x0000;
	i = 0xF;
	while (buf && *buf)
	{
		if (*buf == '#')
			tetr |= 1 << i;
		buf++;
		i--;
	}
	tetr = putleft(tetr);
	return (tetr);
}

uint16_t		putleft(uint16_t tetr)
{
	if (tetr == 0)
		return (0);
	while ((tetr & 0x8888) == 0)
		tetr <<= 1;
	while ((tetr & 0xF000) == 0)
		tetr <<= 4;
	return (tetr);
}

const t_id		g_id[19] = {
	{ "#...#...#...#...", 34952, 1 },
	{ ".#...#..##......", 17600, 2 },
	{ "##..#...#.......", 51328, 2 },
	{ "##...#...#......", 50240, 2 },
	{ "#...#...##......", 35008, 2 },
	{ ".#..##...#......", 19520, 2 },
	{ "#...##..#.......", 35968, 2 },
	{ ".##.##..........", 27648, 2 },
	{ "#...##...#......", 35904, 2 },
	{ "##...##.........", 50688, 2 },
	{ ".#..##..#.......", 19584, 2 },
	{ "###...#.........", 57856, 3 },
	{ "##..##..........", 52224, 2 },
	{ "#...###.........", 36352, 3 },
	{ "###.#...........", 59392, 3 },
	{ "..#.###.........", 11776, 3 },
	{ "###..#..........", 58368, 3 },
	{ ".#..###.........", 19968, 3 },
	{ "####............", 61440, 4 }
};

int				checkid(uint16_t tetr)
{
	int			i;

	i = 0;
	while (i < 19)
	{
		if (tetr == g_id[i].tetr)
			return (i);
		i++;
	}
	return (-1);
}
