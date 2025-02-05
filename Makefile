##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##
CC	=	gcc

CFLAGS	=	-Wall -Wextra -Iinclude

NAME	=	my_ls

SRC     =	src/my_lib.c\
		src/my_lib2.c\
		src/time_sort.c\
		src/long_format.c\
		src/hidden_files.c\
		src/recursive.c\
		src/reverse.c\
		src/flags.c\
		src/directory.c\
		src/main.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
