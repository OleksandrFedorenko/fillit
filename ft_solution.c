/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:17:22 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/14 18:17:22 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern const t_id		g_id[];

int		fillit(t_map *map, t_tetrimino *copy)
{
	int			i;
	t_bit		cur_bits;

	cur_bits = copy->bits;
	cur_bits.full >>= copy->done.x;
	i = 0;
	while (i < copy->height)
	{
		if (cur_bits.pie[i] & map->bit[i + copy->done.y])
			return (0);
		i++;
	}
	i = 0;
	while (i < copy->height)
	{
		map->bit[i + copy->done.y] |= cur_bits.pie[i];
		i++;
	}
	return (1);
}

void	unfill(t_map *map, t_tetrimino *copy)
{
	int			i;
	t_bit		cur_bits;

	cur_bits = copy->bits;
	cur_bits.full >>= copy->done.x;
	i = 0;
	while (i < copy->height)
	{
		map->bit[i + copy->done.y] &= ~cur_bits.pie[i];
		i++;
	}
}

int		done(t_map *map, int index)
{
	t_tetrimino		*copy;
	t_pos			backup;

	copy = &map->copy[index];
	backup = map->dyn_pos[copy->patid];
	copy->done = backup;
	copy->done.x += (copy->done.x > 0) ? g_id[copy->patid].connect : 0;
	while (copy->done.y + copy->height <= map->size)
	{
		while (copy->done.x + copy->width <= map->size)
		{
			if (fillit(map, copy))
			{
				map->dyn_pos[copy->patid] = copy->done;
				if ((index + 1 >= map->copy_count) || (done(map, index + 1)))
					return (1);
				unfill(map, copy);
			}
			copy->done.x++;
		}
		copy->done.y++;
		copy->done.x = 0;
	}
	map->dyn_pos[copy->patid] = backup;
	return (0);
}

void	solve(t_map *map)
{
	map->size = ft_sqrt(map->copy_count * 4);
	while (map->size < 16)
	{
		if (done(map, 0))
		{
			print_map(map);
			break ;
		}
		map->size++;
	}
}
