NAME = fillit

SRC = main.c ft_putleft.c ft_tetrimino.c ft_solution.c ft_print.c ft_read.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME)

%.o: %.c fillit.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	make fclean -C libft

re: fclean all

libft/libft.a:
	make -C libft
