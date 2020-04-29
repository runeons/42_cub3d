NAME = cub3D

CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = ./srcs/bmp.c\
	./srcs/main.c\
	./srcs/raycasting.c\
	./srcs/struct_parsing.c\
	./srcs/check.c\
	./srcs/move.c\
	./srcs/rotate.c\
	./srcs/struct_scene.c\
	./srcs/check_map.c\
	./srcs/parsing.c\
	./srcs/sprites.c\
	./srcs/textures.c\
	./srcs/error.c\
	./srcs/parsing_list.c\
	./srcs/sprites_init.c\
	./srcs/utils_2.c\
	./srcs/key.c\
	./srcs/parsing_map.c\
	./srcs/struct_mlx.c\
	./srcs/utils_1.c

LIB = -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd
INC = -I . -I ./mlx-linux 
OBJ = $(SRC:.c=.o)

OPTION = -L ./libft -lft -L ./mlx-linux\
 

all: $(NAME)

$(NAME): $(SRC) cub3d.h
	$(CC) $(CFLAGS) $(SRC) $(OPTION) $(INC) $(LIB) ./libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
