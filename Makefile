# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 23:29:06 by yamzil            #+#    #+#              #
#    Updated: 2022/04/06 23:57:00 by yamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	so_long.c \
		ft_checkmap.c \
		ft_countline.c \
		ft_elements.c \
		libft/ft_strncmp.c \
		libft/ft_strrchr.c \
		libft/ft_strnstr.c \
		libft/ft_split.c \
		Get_Next_line/get_Next_line.c \
		Get_Next_line/get_next_line_utils.c \
		
INC = so_long.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra


OBJ = $(SRC=.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -I $(INC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	@rm -rf $(OBJ)

fclean :
	@rm -rf $(OBJ) $(NAME)

re :fclean all 