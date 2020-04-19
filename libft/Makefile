NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_lstiter.c ft_putnbr_fd.c ft_substr.c \
ft_bzero.c ft_lstnew.c ft_putstr_fd.c get_next_line.c ft_isdigit.c \
ft_lstsize.c ft_strlen.c ft_lstadd_back.c ft_putchar_fd.c ft_strtrim.c get_next_line_utils.c ft_strcmp.c
OBJ = $(SRC:.c=.o)

OPTION = -c -I .

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(OPTION) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
