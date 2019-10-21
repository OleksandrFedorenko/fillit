/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:08:58 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/26 17:06:29 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_read(int dispf, int f)
{
	char	mem[BUF_SIZE + 1];
	int		last;
	int		i;
	int		c;
	int		j;

	while (1 && !(last = 0))
	{
		if ((i = read(dispf, mem, BUF_SIZE)) == 21)
			last = 1;
		if (i == 20 || i == 21)
		{
			c = 0;
			j = 0;
			mem[i] = '\0';
			if (ft_check(mem, c, j) == 0)
				ft_error();
			if (ft_checkmap(mem, f++) == 0)
				ft_error();
			if (!last)
				break ;
		}
		else
			ft_error();
	}
}

int				ft_checksymb(char *mem)
{
	int		i;
	int		d;
	int		s;

	i = 0;
	d = 0;
	s = 0;
	while (i < 21)
	{
		if (mem[i] == '.')
			d++;
		if (mem[i] == '#')
			s++;
		i++;
	}
	if (d == 12 && s == 4)
		return (1);
	return (0);
}

int				ft_checkmap(char *mem, int f)
{
	int		oh;
	int		line;

	oh = 0;
	line = 0;
	if (f > 25)
		return (0);
	if (!ft_checksymb(mem))
		return (0);
	while (oh < 20)
	{
		while (mem[oh] == '.' || mem[oh] == '#')
			oh++;
		if ((oh - 4) % 5 != 0 || mem[oh] != '\n')
			return (0);
		line++;
		oh++;
	}
	if ((mem[oh] != '\n' && mem[oh] != '\0') || line != 4)
		return (0);
	return (1);
}

int				ft_check(char *mem, int c, int j)
{
	int		ch;

	while (j < 20)
	{
		ch = 0;
		while (mem[j] == ('.') || mem[j] == '#')
		{
			if (mem[j] == '#' && mem[j + 1] == '#')
				c++;
			if (mem[j] == '#' && mem[j + 5] == '#')
				c++;
			if (mem[j] == '#' && mem[j - 1] == '#')
				c++;
			if (mem[j] == '#' && mem[j - 5] == '#')
				c++;
			j++;
			ch++;
		}
		if (mem[j++] == '\n' && ch == 4)
			continue;
		return (0);
	}
	if (c != 6 && c != 8)
		return (0);
	return (1);
}

void			put(int dispf, t_map *map)
{
	char	buffer[547];
	int		split;

	read(dispf, buffer, 546);
	split = 21;
	while (split < (int)ft_strlen(buffer))
	{
		buffer[split - 1] = '@';
		split += 21;
	}
	put_buff(buffer, map);
}
