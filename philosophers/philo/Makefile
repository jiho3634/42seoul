# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 19:08:39 by jihokim2          #+#    #+#              #
#    Updated: 2023/08/24 12:53:42 by jihokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
DR		=	-g -fsanitize=thread
FLAG	=	-Wall -Wextra -Werror

SRCS	=	main.c init.c thread.c  routine.c monitoring.c print.c \
			error.c utils.c etc.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(SRCS)
			cc $(FLAG) $(SRCS) -o $(NAME)
clean	:
			rm -f $(OBJS) $(OBJSB)
			@rm -rf philo.dSYM

fclean	: 
			make clean
			rm -f $(NAME)

re		:
			make fclean
			make all

.PHONY	:	all bonus clean fclean re
