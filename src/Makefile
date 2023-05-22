##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.c) \
		$(wildcard cmd/*.c) \
		$(wildcard tree/*.c) \
		$(wildcard parsing/*.c) \
		$(wildcard others/*.c) \
		$(wildcard operators/*.c) \
		$(wildcard builtins/cd/*.c) \
		$(wildcard builtins/env/*.c) \
		$(wildcard builtins/exit/*.c) \
		$(wildcard builtins/echo/*.c) \
		$(wildcard builtins/alias/*.c) \
		$(wildcard builtins/history/*.c) \
		$(wildcard builtins/variables/*.c) \
		$(wildcard builtins/which_where/*.c) \

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-I./../include -g3

BACK =		../

FLAGS = -W -Wall -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -L./../lib/ -lmy $(FLAGS)
			mv $(NAME) $(BACK)$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BACK)$(NAME)

re:			fclean all
