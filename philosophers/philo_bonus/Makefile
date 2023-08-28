# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 16:22:52 by jihokim2          #+#    #+#              #
#    Updated: 2023/08/24 12:52:40 by jihokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

FLAG	=	-Wall -Wextra -Werror 

SRCS	=	main_bonus.c fork_bonus.c utils_bonus.c

OBJS	=	$(SRCS:.c=.o)

bonus	:	$(NAME)

all		:	$(NAME)

$(NAME)	:	$(SRCS)
			cc $(FLAG) $(SRCS) -o $(NAME) -pthread

clean	:
			rm -f $(OBJS) $(OBJSB)

fclean	:
			make clean
			rm -f $(NAME)

re		:
			make fclean
			make all

.PHONY	:	all bonus clean fclean re
