NAME = Cub3D

CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = ./srcs/*.c
LIB = -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd
INC = -I . -I ./mlx-linux 
OBJ = $(SRC:.c=.o)

OPTION = -L ./libft -lft -L ./mlx-linux\
 

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(OPTION) $(INC) $(LIB) ./libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
