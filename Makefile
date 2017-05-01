##
## Makefile for make in /home/nicolas94200/IA/dante
## 
## Made by goedert nicolas
## Login   <nicolas94200@epitech.net>
## 
## Started on  Mon May  1 12:27:09 2017 goedert nicolas
## Last update Mon May  1 12:27:11 2017 goedert nicolas
##

NAME	=	solver

SRC	=	tournament/src/main.c	\
		tournament/src/string1.c	\
		tournament/src/string2.c	\
		tournament/src/wordtab.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -I./tournament/inc -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		mv $(NAME) ./tournament
		make -C ./astar
		make -C ./breadth
		make -C ./depth
		make -C ./generator

clean	:
		$(RM) $(OBJ)

fclean	: 	clean
		$(RM) $(NAME)
		make fclean -C ./astar
		make fclean -C ./breadth
		make fclean -C ./depth
		make fclean -C ./generator

re	:	fclean all

.PHONY	:	all clean fclean re
