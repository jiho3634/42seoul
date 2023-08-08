# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 19:08:39 by jihokim2          #+#    #+#              #
#    Updated: 2023/08/07 19:55:26 by jihokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRCS	=	main.c init.c thread.c error.c utils.c\
			routine.c eating.c monitoring.c print.c 

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(SRCS)
			@cc -Wall -Wextra -Werror $(SRCS) -o $(NAME)
			@ls $(NAME)

clean	:
			@rm -f $(OBJS) $(OBJSB)

fclean	: 
			@make clean
			@rm -f $(NAME)

re		:
			@make fclean
			@make all

.PHONY	:	all bonus clean fclean re
