##
## Makefile for make in /home/nicolas94200/IA/dante/generator
## 
## Made by goedert nicolas
## Login   <nicolas94200@epitech.net>
## 
## Started on  Mon May  1 12:32:45 2017 goedert nicolas
## Last update Mon May  1 12:32:46 2017 goedert nicolas
##

NAME	=	generator

SRC	=	src/main.c	\
		src/string1.c	\
		src/string2.c	\
		src/wordtab.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -I./inc -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -I./inc

clean	:
		$(RM) $(OBJ)

fclean	: 	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
