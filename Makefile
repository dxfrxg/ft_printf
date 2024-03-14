NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_FILES = ft_printf.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) -c $(CFLAGS) $(SRC_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re