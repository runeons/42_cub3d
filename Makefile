#****************************************************************************#
#*** GENERAL ****************************************************************#
#****************************************************************************#

NAME 		=	cub3D

CPL			=	clang
FLAGS		=	-Wall -Wextra -Werror

#****************************************************************************#
#*** LIBRARIES **************************************************************#
#****************************************************************************#

LIB = -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd
INC = -I . -I ./mlx-linux 
OPTION		=	-L ./libft -lft -L ./mlx-linux\

#****************************************************************************#
#*** SRCS/OBJS **************************************************************#
#****************************************************************************#

SRCS			= \
				./srcs/bmp.c\
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

OBJ = $(SRCS:.c=.o)
 
#****************************************************************************#
#*** RULES ******************************************************************#
#****************************************************************************#

all: $(NAME)

$(NAME): $(SRCS) cub3d.h
	$(CC) $(CFLAGS) $(SRCS) $(OPTION) $(INC) $(LIB) ./libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
