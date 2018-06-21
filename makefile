NAME = test_gnl

FLAGS = -Wall -Werror -Wextra

HEAD = -I./ 

LIB = -L libft -lft

SRCS = get_next_line.c test.c

OBJ = $(SRCS:.c=.o)

NAME: $(OBJ)
	make -C libft re && make -C libft clean
	clang $(FLAGS) -c $(SRCS)
	clang -o $(NAME) $(FLAGS) $(LIB) $(HEAD) $(OBJ)

all: NAME

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean fclean $(NAME)

.PHONY: re clean fclean all