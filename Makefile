#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 16:06:44 by mel-ghar          #+#    #+#              #
#    Updated: 2020/01/26 20:40:01 by mel-ghar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ./CUB3D
SRC = 	unr1.c			\
		unr2.c			\
		unr3.c			\
		unr4.c			\
		unr5.c			\
		unr6.c			\
		unr7.c			\
		unr8.c			\
		unr9.c			\
		draw1.c			\
		draw2.c			\
		draw3.c			\
		draw4.c			\
		draw5.c			\
		draw6.c			\
		draw7.c			\
		sprite1.c		\
		sprite2.c		\
		move1.c			\
		move2.c			\
		bitmap.c		\
		getinfo.c		\
		getinfohelp1.c	\
		getinfohelp3.c	\
		main.c			\
		get_next_line.c	\
		get_next_line_utils.c \

BSRC =	bouns/unr1.c			\
        bouns/unr2.c			\
        bouns/unr3.c			\
        bouns/unr4.c			\
        bouns/unr5.c			\
        bouns/unr6.c			\
        bouns/unr7.c			\
        bouns/unr8.c			\
        bouns/unr9.c			\
        bouns/draw1.c			\
        bouns/draw2.c			\
        bouns/draw3.c			\
        bouns/draw4.c			\
        bouns/draw5.c			\
        bouns/draw6.c			\
        bouns/draw7.c			\
        bouns/sprite1.c			\
        bouns/sprite2.c			\
        bouns/move1.c			\
        bouns/move2.c			\
        bouns/bitmap.c			\
        bouns/getinfo.c			\
        bouns/getinfohelp1.c	\
        bouns/getinfohelp3.c	\
        bouns/main.c			\


all:$(NAME)
$(NAME):
	gcc $(SRC)  -Wall -Werror -Wextra -D BUFFER_SIZE=10 -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus:
	gcc $(SRC)  -Wall -Werror -Wextra -D BUFFER_SIZE=10 -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	rm -f $(NAME)
fclean:clean

re:fclean all

.PHONY: re clean fclean bonus
