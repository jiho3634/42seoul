# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim2 <jihokim2@student.42seoul.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 16:27:18 by jihokim2          #+#    #+#              #
#    Updated: 2023/04/28 17:09:17 by jihokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	server client
SRCS	=	server.c client.c

all		:	$(NAME)

$(NAME)	:	$(SRCS)
			cc -Wall -Wextra -Werror server.c -o server
			cc -Wall -Wextra -Werror client.c -o client

clean	:
			rm -f $(NAME)

fclean	:
			make clean

re		:
			make fclean
			make all

.PHONY	:	all clean fclean re
