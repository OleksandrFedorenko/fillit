/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:05:22 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/19 19:11:01 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int		dispf;
	t_map	table;
	int		f;

	f = 0;
	dispf = open(av[ac - 1], O_RDONLY);
	if (ac == 2)
		ft_read(dispf, f);
	else
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		exit(0);
	}
	close(dispf);
	dispf = open(av[ac - 1], O_RDONLY);
	ft_memset(&table, 0, sizeof(table));
	put(dispf, &table);
	close(dispf);
	solve(&table);
	return (0);
}
