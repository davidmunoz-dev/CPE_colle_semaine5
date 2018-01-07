##
## Makefile for makefile in /home/peau_c/CPE_colle_semaine6
##
## Made by clement peau
## Login   <peau_c@epitech.net>
##
## Started on  Tue May 31 19:06:41 2016 clement peau
## Last update Tue May 31 21:59:03 2016 clement peau
##

SRC	= src/main.c 		\
	  src/get_file.c	\
	  src/bzero.c		\
	  src/color_pixel.c	\

OBJ	= $(SRC:.c=.o)

NAME	= bob_ross

CFLAGS	= -W -Wall -Wextra -Werror

HEAD	= -Iinc/

CC	= gcc $(HEAD)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
