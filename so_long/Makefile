# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 18:38:25 by jihokim2          #+#    #+#              #
#    Updated: 2023/05/17 02:44:46 by jihokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	so_long.h get_next_line.h
SRCS	=	main.c error.c sub_map_check.c sub_main.c sub_path_check.c\
		   	get_next_line.c get_next_line_utils.c ft_memset.c\
			sub_mlx.c sub_key_press.c
OBJ		=	$(SRCS:.c=.o)
MLX  	=   ./mlx/libmlx.a
MLXDIR  =  ./mlx

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(MLX)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o		:	%.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -I $(INC) 

$(MLX) :
	$(MAKE) -C $(MLXDIR)

clean	:
	@rm -f $(OBJ)

fclean	: 
	@make clean
	@rm -f $(NAME)

re		:
	make fclean
	make all

.PHONY	:	all bonus clean fclean re
