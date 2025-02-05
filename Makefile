NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

MLX_INCLUDE = -Iminilibx-linux

SRC = ft_split.c utils.c get_next_line.c get_next_line_utils.c read_map.c parsing.c animation.c\
	  freeing.c flood.c drawing.c moves.c calculate.c count_and_store.c update.c main.c 

SRC_FTPRINTF = ft_printf/ft_check_spec.c \
               ft_printf/ft_puthex.c \
               ft_printf/ft_putptr.c \
               ft_printf/ft_putunbr.c \
               ft_printf/ft_printf.c \
               ft_printf/ft_putchar.c \
               ft_printf/ft_putnbr.c \
               ft_printf/ft_putstr.c

OBJ = $(SRC:.c=.o)

OBJ_FTPRINTF = $(SRC_FTPRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)	$(OBJ_FTPRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_FTPRINTF) $(MLX_FLAGS) -o $(NAME)


%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(MLX_INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_FTPRINTF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re

.SECONDARY:
