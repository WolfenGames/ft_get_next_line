#
#It does the thing where it makes the files for me
#

NAME = libft.a

CFLAGS += -Wextra -Wall -Werror -I./inlcudes

SOURCES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
		  ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		  ft_strlcat.c ft_strchr.c ft_strncat.c ft_strstr.c \
		  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		  ft_isalpha.c ft_isalnum.c ft_putchar.c ft_putstr.c\
		  ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c \
		  ft_isdigit.c ft_strrchr.c ft_putendl.c ft_memalloc.c \
		  ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		  ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putnbr.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_intminmax.c \
		  ft_strtrimcpy.c ft_clearspace.c ft_wordcount.c

all: $(NAME)


OBJECTS = $(SOURCES:.c=.o)

C = gcc -Wall -Wextra -Werror

%.o:	%.c
	@echo "\033[1;36;m[Compiling $<]\t\t\t\033[0m: " | tr -d '\n'
	$(C) -c $< -I.

$(NAME): $(OBJECTS)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	ar r $(NAME) $(OBJECTS)
	@echo "\033[1;32;m[Success] \t\t\t\033[0m" 
	ranlib $(NAME)
	@echo "\033[1;34;m[RUNUNG RANLIB] \t\t\033[0m"

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
