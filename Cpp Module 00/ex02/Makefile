NAME			=	tests

SRC				=	$(shell ls | grep -E ".+\.cpp")
CC				=	c++
CFLAGS			=	-Wall -Werror -Wextra -std=c++98

all				:	$(NAME)

$(NAME)			:	$(SRC)
					$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean			:
					@#

fclean			:	clean
					rm -rf $(NAME)

re				:	fclean all

.PHONY			:	all fclean clean re
