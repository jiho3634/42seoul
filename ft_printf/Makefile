# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 16:27:18 by jihokim2          #+#    #+#              #
#    Updated: 2022/12/09 16:27:50 by jihokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c function_csp.c function_xX.c function_idu.c
INC		=	ft_printf.h
OBJECTS =	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			ar -crs $@ $^

%.o		:	%.c
			cc -c -Wall -Wextra -Werror $< -o $@ -I $(INC)

clean	:
			rm -f $(OBJECTS)

fclean	:
			make clean
			rm -f $(NAME)

re		:
			make fclean
			make all

.PHONY	:	all clean fclean re
