/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:53:43 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/19 19:13:24 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 21

typedef union		u_bit
{
	uint16_t		pie[4];
	uint64_t		full;
}					t_bit;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_tetrimino
{
	int				patid;
	t_bit			bits;
	int				width;
	uint16_t		tetr;
	int				height;
	t_pos			done;
}					t_tetrimino;

typedef struct		s_map
{
	t_tetrimino		copy[26];
	int				copy_count;
	int				size;
	uint16_t		bit[16];
	t_pos			dyn_pos[19];
}					t_map;

typedef struct		s_id
{
	char			raw[16];
	uint16_t		tetr;
	int				connect;
}					t_id;

/*
**					ft_read.c
*/
void				put(int dispf, t_map *map);
void				ft_read(int dispf, int f);
int					ft_checkmap(char *mem, int f);
int					ft_check(char *mem, int c, int j);
int					ft_checksymb(char *mem);
/*
**					ft_putleft.c
*/
uint16_t			tobinary(char *buf);
uint16_t			putleft(uint16_t tetr);
int					checkid(uint16_t tetr);
/*
**					ft_tetrimino.c
*/
void				maketetrimino(char *tetrimino, t_tetrimino *copy);
void				put_buff(char *buff, t_map *map);
void				putinlst(t_tetrimino *copy);
/*
**					ft_solution.c
*/
void				solve(t_map *map);
int					done(t_map *map, int tetri_index);
int					fillit(t_map *map, t_tetrimino *copy);
void				unfill(t_map *map, t_tetrimino *copy);
/*
**					ft_print.c
*/
void				ft_error(void);
void				print_map(t_map *map);
void				letter(char *table, int map_size, \
					t_tetrimino *copy, int number);

#endif
