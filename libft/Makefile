# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 19:08:39 by jihokim2          #+#    #+#              #
#    Updated: 2022/12/07 19:09:01 by jihokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS	=	-src
INC		=	./libft.h
SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS_B	=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
			ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef BONUS
	FILES =	$(OBJS) $(OBJS_B)
else
	FILES =	$(OBJS)
endif

all		:	$(NAME)

bonus	:
	@make BONUS=1

$(NAME)	:	$(FILES)
	@$(AR) $(ARFLAGS) $@ $^

%.o		:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean	:
	@rm -f $(OBJS) $(OBJS_B)

fclean	: 
	@make clean
	@rm -f $(NAME)

re		:
	make fclean
	make all

.PHONY	:	all bonus clean fclean re
