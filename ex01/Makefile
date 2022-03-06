# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 14:06:05 by graja             #+#    #+#              #
#    Updated: 2022/03/04 18:08:54 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex00

SRCS	=	main.cpp

CC	=	c++

FLAGS	=	-Wextra -Werror -Wall -Wconversion -std=c++98 

OBJ	=	${SRCS:.cpp=.o}

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY: all clean fclean re
